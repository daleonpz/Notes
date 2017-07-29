function[t, m] = verifica(Nrows, Ncols)

if( nargin < 2)
  Ncols = Nrows;
end


fid = fopen('t.raw', 'r');
t = fread(fid, inf, 'int');
t = reshape(t, Nrows, Ncols);
fclose(fid);

fid = fopen('m.raw', 'r');
m = fread(fid, inf, 'int');
m = reshape(m, Nrows, Ncols);
fclose(fid);

tmat = transpose(m);

norm(t(:) - tmat(:))
