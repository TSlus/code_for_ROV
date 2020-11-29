clear;clc;
addpath(genpath('Models'));
name1 = 'model.mat';
name2 = 'bronze.mat';

%% input
% 1.mesh
load(name1);

% 2.number of candidate points
% nCand = ceil(size(faces, 1)/2);
% nCand = ceil(size(faces, 1)/2*3/5);
nCand = ceil(size(faces, 1)*2/5);

% 3.the level of detail, high curvature old points -- CSP
k_level = ceil(nCand*2/5); % quarter of nCand

%% do Retiling and PPS
detail_plot = 0;

Retiling_and_PPS;