module spacer(h, d, fn){
    difference(){
      cylinder (h = h, d=d, $fn=fn);
      cylinder (h = h, d=d-1, $fn=fn);
    }
}

spacer(12, 8, 20);