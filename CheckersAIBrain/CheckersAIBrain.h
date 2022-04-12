﻿/* CheckersAIBrain.h 
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
    NeuralNetImpl(int inputSize, int hiddenSize, int hiddenSize2, int outputSize)
        : hidden1(inputSize, hiddenSize), hidden2(hiddenSize, hiddenSize), hidden3(hiddenSize, hiddenSize2), out(hiddenSize2, outputSize)
    {
        register_module("hidden1", hidden1);
        register_module("hidden2", hidden2);
        register_module("hidden3", hidden3);
        register_module("out", out);

    }
    torch::Tensor forward(torch::Tensor x) {  
        x = torch::leaky_relu(hidden1(x));
        x = torch::selu(hidden2(x));
        x = torch::relu(hidden3(x));
        x = torch::tanh(out(x));
        return x;
    }

    torch::nn::Linear hidden1{ nullptr }, hidden2{ nullptr }, hidden3{ nullptr }, out{ nullptr };
};
TORCH_MODULE(NeuralNet);

bool saveNetwork(NeuralNet& net, int session, int saveNum);
NeuralNet loadNetwork(int session, int saveNum);
bool loadLatestNetwork(NeuralNet& net, int& outSession, int& outSaveNum);

#endif // !CHECKERS_AI_BRAIN_H