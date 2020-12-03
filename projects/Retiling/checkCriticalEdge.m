function [re_flag, crirical_tri] = checkCriticalEdge(...
    nearP,faces_Mutual, nearPsp, xy)

n_near = length(nearP);
crirical_tri = zeros(n_near, 4); t_ce = 1;
re_flag = 1; loopf1 = 0;
for ip = nearP
    [rip, ~] = find(faces_Mutual == ip);
    triRing = faces_Mutual(rip,:);
    
    for j = 1:size(triRing, 1)
        a = triRing(j, 1);
        idx1 = find(nearP == a, 1); if isempty(idx1); continue; end % 362.708s 553591729次
        b = triRing(j, 2);
        idx2 = find(nearP == b, 1); if isempty(idx2); continue; end
        c = triRing(j, 3);
        idx3 = find(nearP == c, 1); if isempty(idx3); continue; end
        
        aif = nearPsp(c, b); bif = nearPsp(a, c); cif = nearPsp(b, a);
        ceif = find(~[aif, bif, cif]);
        if length(ceif) ~= 1 % 如果三条边都不是critical edge
            continue;
        end
        
        crirical_tri(t_ce, 1:3) = triRing(j, :);
        crirical_tri(t_ce, 4) = triRing(j, ceif); t_ce = t_ce+1;
        
        idxs = [idx3, idx2, idx1; idx1, idx3, idx2; idx2, idx1, idx3];
        idxs = idxs(ceif, :); % c, b, a 在邻域点钟的位置
        e1 = xy(idxs(2), :) - xy(idxs(3), :);
        e2 = xy(idxs(1), :) - xy(idxs(3), :);
        mcross = cross([e1, 0], [e2, 0]);
        if mcross(3) < 0 % 点1不可以去除，不做三角化
            re_flag = 0; loopf1 = 1; break;
        end
        break; % 每个邻域点只会有一种 critical顶点 情形。
    end
    if loopf1 ; break; end
end

crirical_tri = crirical_tri(1:(t_ce-1),:);
end