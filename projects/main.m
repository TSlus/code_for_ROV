clear;clc;
addpath(genpath('Models'));
name1 = 'model.mat';
name2 = 'bronze.mat';

%% input
% 1.mesh
modelname = name2;
load(modelname);
modelname = 0;% when you want to use the saved data, need it.

% 2.number of candidate points
% nCand = ceil(size(faces, 1)/2);
% nCand = ceil(size(faces, 1)/2*3/5);
nCand = ceil(size(faces, 1)*2/5);

% 3.the level of detail, high curvature old points -- CSP
k_level = ceil(nCand*2/5); % quarter of nCand

% 4.methods for remove old vertices
method = 3; % 1,2,3，both = 1,2,3，4

%% do Retiling and PPS
detail_plot = 0;
Retiling_and_PPS;

