

int lengthOfLongestSubstring(char* s) {
    int charmap[128];
    for(int i=0; i < 128; i++){
        charmap[i] = -1;
    }
    int window_size = 0;
    int window_lower = 0;
    int window_upper = 0;
    // advance upper
    while(1){
        char cu = s[window_upper];
        if(cu == '\0' ){return window_size;}
        if(charmap[cu] == -1){
            charmap[cu] = window_upper;
            window_upper++;
            // update max windows size
            int wsize = window_upper - window_lower;
            if(wsize > window_size){
                window_size = wsize;
            }
        }else{
            //advance lower
            int idx = charmap[cu];
            for(;window_lower <= idx; window_lower++){
                char cl = s[window_lower];
                charmap[cl] = -1;
            }
        }
    }
}
