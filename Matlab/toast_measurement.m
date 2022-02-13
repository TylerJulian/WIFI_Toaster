
i1 = imread("toast1.jpg");
i1 = imcrop(i1, [600 500 800 625]);
i5 = avg_color(i1);

i2 = imread('toast2.jpg');
i2 = imcrop(i2, [400 600 700 700]);
i6 = avg_color(i2);

i3 = imread('toast3.jpg');
i3 = imcrop(i3, [600 400 800 600]);
i7 = avg_color(i3);

i4 = imread('toast4.jpg');
i4 = imcrop(i4, [400 600 700 700]);
i8 = avg_color(i4);

subplot(4,2,1);
axis('image');

imshow(i1);
title('plain bread')

subplot(4,2,2);
imshow(i5);
title('average color of plain bread')

subplot(4,2,3);
axis('image');
imshow(i2);
title('toasted bread 1')

subplot(4,2,4);
imshow(i6);
title('average color of toasted bread 1')

subplot(4,2,5);
axis('image');
imshow(i3);
title('toasted bread 2')

subplot(4,2,6);
imshow(i7);
title('average color of toasted bread 2')

subplot(4,2,7);
axis('image');
imshow(i4);
title('burnt bread')

subplot(4,2,8);
imshow(i8);
title('average color of burnt bread')

function Iout = avg_color(I)
    %https://www.mathworks.com/matlabcentral/answers/370094-how-to-get-the-average-rgb-values-of-a-given-region-and-then-set-the-region-to-that-color
    i_r_channel = I(:,:,1);
    i_g_channel = I(:,:,2);
    i_b_channel = I(:,:,3);
    % Extract the black
    gray = rgb2gray(I);
    idx = gray == 0;
    % Calculate average 
    Ravg = uint8(mean(i_r_channel(~idx)));
    Gavg = uint8(mean(i_g_channel(~idx)));
    Bavg = uint8(mean(i_b_channel(~idx)));
    % Set the region to average RGB
    i_r_channel(~idx) = Ravg;
    i_g_channel(~idx) = Gavg;
    i_b_channel(~idx) = Bavg;
    Iout = cat(3,i_r_channel,i_g_channel,i_b_channel);
end