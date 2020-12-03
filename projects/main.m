clear;clc;
addpath(genpath('Models'));
name1 = 'model.mat';
name2 = 'bronze.mat';

%% input
% 1.mesh
modelname = name1;
load(modelname);

% 2.number of candidate points
% nCand = ceil(size(faces, 1)/2);
% nCand = ceil(size(faces, 1)/2*3/5);
nCand = ceil(size(faces, 1)*2/5);

% 3.the level of detail, high curvature old points -- CSP
k_level = ceil(nCand*2/5); % quarter of nCand

% 4.methods for remove old vertices
method = 3; % 1,2,both = 1,2,3

%% do Retiling and PPS
detail_plot = 0;
Retiling_and_PPS;