clear;clc
% save  data1.txt  vertices -ascii 
% mvertices = load('C:\Users\Husen_Li\Desktop\studyFile\CPP\Project1\out.txt');
vertices = load('vertices_Mutual.txt');
faces = load('faces_Mutual.txt');
trimesh(faces, vertices(:,1),vertices(:,2),vertices(:,3));axis equal;
CSP_idx = load('CSP_idx.txt');
max(CSP_idx)
min(CSP_idx)

vertices = vertices';
faces = faces';
obj_write('myobjm2.obj',vertices,faces);