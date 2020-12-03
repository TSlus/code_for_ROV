function [faces_add2, re_flag, mcontinue] = addFace(xy, nearP, crirical_tri)

faces_add2 = [];
n_near = length(nearP);
re_flag = 1; mcontinue = 0;
lastwarn('');
warning ('off');
polyin = polyshape(xy(:,1), xy(:,2));
T = triangulation(polyin);

[msg, ~] = lastwarn;
if ~isempty(msg)
    lastwarn('');
    warning ('on');
    mcontinue = 1;
    return;
end
warning ('on');

% 加入的面
adj_near = [1, n_near:-1:2];
adj_idxs = nearP(adj_near);
faces_add2 = adj_idxs(T.ConnectivityList);

% 再次小心判断，如果新加入的面中，只有一个面与ce对点相关
% 由于本身ce的存在，就形成了2度点
for j = 1:size(crirical_tri, 1)
    valence_ce = find(faces_add2 == crirical_tri(j,4));
    if length(valence_ce) == 1; re_flag = 0; break; end
end

end