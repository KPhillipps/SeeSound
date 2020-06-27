/*  based on this article  https://dlbeer.co.nz/articles/fftvis.html
    The instantaneous bar heights vary quite wildly, and even after applying the two improvements above, 
    they flicker if plotted directly. Instead, we blend the instaneous values with the per-slice values from the last frame:
    
    B_i' = B_(i-1)' * s' + B_i * (1 - s')
    
    Where B_i represents the instantaneous value, and B_i' represents the smoothed value. 
    s' is a smoothing constant which is adjusted for the actual slice rate so as to give approximately the same results 
    over a range of different sample rates: s' = s ** (1 / R)
    In the above, s is the base smoothing constant, and R is the slice rate.
    
    each band is going to have to be smoothed seperately
    test smoothing at different rates for different frequencies
*/
