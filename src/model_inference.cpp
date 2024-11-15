#include "model_inference.h"
#include <tensorflow/core/public/session.h>
#include <tensorflow/core/platform/env.h>
#include <iostream>

std::vector<double> runModelInference(const std::vector<double>& features) {
    std::vector<double> predictions;

    // Load the trained model (replace with your own path)
    tensorflow::Session* session;
    tensorflow::Status status = tensorflow::NewSession(tensorflow::SessionOptions(), &session);
    if (!status.ok()) {
        std::cerr << "Error creating session: " << status.ToString() << std::endl;
        return predictions;
    }

    tensorflow::GraphDef graph_def;
    status = tensorflow::ReadBinaryProto(tensorflow::Env::Default(), "model.pb", &graph_def);
    if (!status.ok()) {
        std::cerr << "Failed to load model: " << status.ToString() << std::endl;
        return predictions;
    }

    status = session->Create(graph_def);
    if (!status.ok()) {
        std::cerr << "Failed to create session: " << status.ToString() << std::endl;
        return predictions;
    }

    // Run the model with preprocessed data as input
    tensorflow::Tensor input_tensor(tensorflow::DT_FLOAT, tensorflow::TensorShape({1, features.size()}));
    for (size_t i = 0; i < features.size(); ++i) {
        input_tensor.matrix<float>()(0, i) = features[i];
    }

    std::vector<tensorflow::Tensor> outputs;
    status = session->Run({{"input_layer", input_tensor}}, {"output_layer"}, {}, &outputs);
    if (!status.ok()) {
        std::cerr << "Error running session: " << status.ToString() << std::endl;
        return predictions;
    }

    // Extract predictions (assuming one output layer)
    for (int i = 0; i < outputs[0].dim_size(1); ++i) {
        predictions.push_back(outputs[0].matrix<float>()(0, i));
    }

    return predictions;
}
