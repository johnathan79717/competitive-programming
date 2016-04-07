function cylinder( W, H )
    step = 0.001;
    x = 0:step:W;
    for k = 1:length(x)
        a(k) = volume(W, H, x(k));
    end
    plot(x, a);
    hold on
    if(W / H > pi + 2) 
        plot(W - pi * H, volume(W, H, W - pi * H), 'ro');
    elseif(W / H < 1 + 1/pi)
        plot(H / pi, volume(W, H, H / pi), 'ro');
    elseif(W/H < (pi + 1) / 2)
        plot(W / (pi + 1), volume(W, H, W / (pi + 1)), 'ro');
    else
        aa = 4 * (pi + 1) ^ 2;
        bb = -4 * H - 4 * (pi + 1) * W;
        cc = W^2 + H^2;
        R = (-bb - sqrt(bb^2 - 4 * aa * cc)) / 2 / aa;
        plot(W - 2 * pi * R, volume(W, H, W - 2 * pi * R), 'ro');
        R
    end
    hold off
%     [A I] = max(a);
%     x(I)
end