a =dlmread('polar.dat')
s = a(:,1) + 1;
b = a(:,2);
c = a(:,3);
d=a(:,4)


for  i=1:20
  stem(s(i*100-99:i*100),b(i*100-99:i*100),'r');
  axis([1 2000 -1 2])
  stem(s(i*100-99:i*100),c(i*100-99:i*100),'b');
    stem(s(i*100-99:i*100),d(i*100-99:i*100),'g');
  hold on;
  pause(1);

end 




 
