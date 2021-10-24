function y=Implication_MIN(beta,muyy)
K=length(muyy);
y=zeros(size(muyy));
for k=1:K
    y(k)= min(beta, muyy(k));
end
end