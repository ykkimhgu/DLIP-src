%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Image Processing with Deep Learning 
% by YKKIM
% 2021 - Spring
% Tutorial:  Spatial Filtering 
% 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


% u,v: image points
% s,t: kernel points
% w: kernel, w(s,t)
% f: source image, f(x,y)

clc; clear all; close all;

% image read
f = imread('Pattern_original.tif');
f = im2gray(f);
[M, N] = size(f);

figure, imshow(f)

% define window
w =[1  1 1 1 1 
    1  1 1 1 1 
    1  1 1 1 1 
    1  1 1 1 1 
    1  1 1 1 1];

[wM, wN] = size(w);
wSum = sum(w(:));
if(wSum == 0)
    wSum = 1;
end

%Padding
% e.g. 3 x 3 Filter -> pad 1 each side or 2 total
b = (wM - 1) / 2; % b: yPad
a = (wN - 1) / 2; % a: xPad

% fPad image index: [1 to M+(2*b)] x [1 to N+(2*a)]
fPad = zeros(M+wM-1,N+wN-1);
fPad(a+1:a+M,b+1:b+N) = double(f);
figure, imshow(uint8(fPad))


% apply 2D-convolution
gPad = zeros(size(fPad));
tic
for v = b+1:b+M  % src 가 있는 지점부터 시작 e.g. 2
    for u = a+1:a+N
        % convolution of kernel at one point (u,v)
        conv = 0;
        for t = -b:b
            for s = -a:a
                % Your code goes here;
                % Your code goes here;
            end
        end
        gPad(v,u) = conv / wSum;
    end
end
g = gPad(b+1:b+M, a+1:a+N); % cropping
toc
figure, imshow(uint8(g))