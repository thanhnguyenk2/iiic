function y=Or_BSUM(muyA,muyB)
K=length(muyA);
y=zeros(size(muyA));
for k=1:K
    y(k)= min(muyA(k)+ muyB(k), 1);
end
end