/* CheckersAIBrain.h 
Nathan Damon
CS 405
4/5/2022
This is the header file for using the neural network features from PyTorch
*/

#ifndef CHECKERS_AI_BRAIN_H
#define CHECKERS_AI_BRAIN_H

#include <iostream>
#include <torch/torch.h>

bool openMappedFile();
bool closeMappedFile();

struct NeuralNetImpl : torch::nn::Module
{
    NeuralNetImpl(int inputSize, int hiddenSize, int outputSize)
        : hidden1(inputSize, hiddenSize), hidden2(hiddenSize, hiddenSize), out(hiddenSize, outputSize)
    {
        register_module("hidden1", hidden1);
        register_module("hidden2", hidden2);
        register_module("out", out);

    }
    torch::Tensor forward(torch::Tensor x) {
        std::cout << "forward start" << "\n";
        //std::cout << x << "\n";
        x = torch::leaky_relu(hidden1(x));
        //std::cout << x << "\n";
        x = torch::tanh(hidden2(x));
        //std::cout << x << "\n";
        x = torch::selu(out(x));
        std::cout << "forward end" << "\n";
        return x;
    }

    torch::nn::Linear hidden1{ nullptr }, hidden2{ nullptr }, out{ nullptr };
};
TORCH_MODULE(NeuralNet);

bool saveNetwork(NeuralNet& net, int session, int saveNum);
NeuralNet loadNetwork(int session, int saveNum);
bool loadLatestNetwork(NeuralNet& net, int& outSession, int& outSaveNum);

#endif // !CHECKERS_AI_BRAIN_H