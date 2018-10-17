A = importdata('estimates2s.mat');
B = importdata('actualstates2s.mat');

n=1:length(A(2,:))-1;
figure(1)
subplot(2,1,1);
plot(n,A(2,n));
hold on;
subplot(2,1,2);
plot(n,B(5,n));
hold off;

