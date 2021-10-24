x=-8:0.01:6;
muyA=hlt_hinhthang(x,-7,-3,-3,5);
muyB=hlt_hinhthang(x,-5,2,2,4);
muyC=Or_BSUM(muyA,muyB)
plot(x,muyA,'r',x,muyB,'b',x,muyC,'g');
