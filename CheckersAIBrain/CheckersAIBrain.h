/* CheckersAIBrain.h 
Nathan Damon
CS 405
4/5/2022
This is the header file for using the neural network features from PyTorch
*/

#ifndef CHECKERS_AI_BRAIN_H
#define CHECKERS_AI_BRAIN_H

#include <torch/torch.h>

bool openMappedFile();
bool closeMappedFile();

struct NeuralNetImpl : torch::nn::Module
{
    NeuralNetImpl(int inputSize = 32, int hiddenSize1 = 33, int hiddenSize2 = 24, int outputSize = 1)
        : hidden1(inputSize, hiddenSize1), hidden2(hiddenSize1, hiddenSize1), hidden3(hiddenSize1, hiddenSize2), out(hiddenSize2, outputSize)
    {
        register_module("hidden1", hidden1);
        register_module("hidden2", hidden2);
        register_module("hidden3", hidden3);
        register_module("out", out);

    }
    torch::Tensor forward(torch::Tensor x) {  
        x = torch::leaky_relu(hidden1(x));
        x = torch::hardswish(hidden2(x));
        x = torch::selu(hidden3(x));
        x = torch::sigmoid(out(x));
        return x;
    }

    torch::nn::Linear hidden1{ nullptr }, hidden2{ nullptr }, hidden3{ nullptr }, out{ nullptr };
};
TORCH_MODULE(NeuralNet);

bool saveNetwork(NeuralNet& net, int session, int saveNum);
NeuralNet loadNetwork(int session, int saveNum);
bool loadLatestNetwork(NeuralNet& net, int& outSession, int& outSaveNum);

#endif // !CHECKERS_AI_BRAIN_H