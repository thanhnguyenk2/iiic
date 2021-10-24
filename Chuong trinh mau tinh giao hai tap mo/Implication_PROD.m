function y=Implication_PROD(beta,muyy)
K=length(muyy);
y=zeros(size(muyy));
for k=1:K
    y(k)= beta * muyy(k);
end
end