function[] = performance(ini)

vo = dir('outputs/o.*');
vb = dir('outputs/b.*');
vf = dir('outputs/f.*');

N = length(vo);

tick0 = zeros(N,1);
tick1 = zeros(N,1);

for k=1:N,

  fid = fopen(vo(k).name);
  p0 = fscanf(fid, '%d');
  fclose(fid);

  fid = fopen(vb(k).name);
  p1 = fscanf(fid, '%d');
  fclose(fid);
  
  tick0(k) = median(p0);
  tick1(k) = median(p1);
  
end

expo = [4 5 6 7 8 9 10 11 12 ];

T_work0 = tick0(:);
T_work1 = tick1(:);

semilogy(expo, sort(T_work0),'--bs','LineWidth',1,...
                       'MarkerEdgeColor','r',...
                       'MarkerFaceColor','k',...
                       'MarkerSize',5);
hold on;

semilogy(expo, sort(T_work1),'--bs','LineWidth',1,...
                       'MarkerEdgeColor','g',...
                       'MarkerFaceColor','k',...
                       'MarkerSize',5);
% hold on;
% 
% semilogy(expo, sort(T_work2),'--bs','LineWidth',1,...
%                        'MarkerEdgeColor','b',...
%                        'MarkerFaceColor','k',...
%                        'MarkerSize',5);                  
%      
        