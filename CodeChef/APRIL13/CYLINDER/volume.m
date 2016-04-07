function [v R A] = volume(W, H, x)
    if x < H / 2
        R = x / 2;
    elseif x > 2 * H
        R = H / 2;
    else
        R = (x + H - sqrt(2 * H * x)) / 2;
    end
    
    if H < 2 * pi * R
        if W - x < 2 * pi * R
            A = 0;
        else
            A = H;
        end
    else
        if W - x < 2 * pi * R
            A = W - x;
        elseif W - x > H
            A = W - x;
        else
            A = H;
        end
    end
    v = pi * R * R * A;
end