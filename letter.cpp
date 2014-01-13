class Letter
{
#define LETTER_W  (16)
#define LETTER_H  (16)
#define LETTER_SCALE (1.0f)
#define LETTER_X  (10)
#define LETTER_Y  (10)

public:
   ~Letter();

   Letter(ImagePtr img = NULL, int width = LETTER_W, int height = LETTER_H, flt scale = LETTER_SCALE, int xcount = LETTER_X, int ycount = LETTER_Y)
   {
      this.image = img;
      this.scale = scale;

      if( img != NULL)
      {
         this.u =  flt(width) / img->w();      
         this.v = flt(height) / img->h();
         this.screen_x = -D.w();
         this.screen_y = D.h();
      }
      
      this.xsize = xcount;
      this.ysize = ycount;
   }

   void set(ImagePtr img = NULL, int width = LETTER_W, int height = LETTER_H)
   {
      this.image = img;
      if( img != NULL)
      {
         this.u =  width / this.image->w();
         this.v = height / this.image->h();
         this.screen_x = -D.w();
         this.screen_y = D.h();
      }
   }

   void draw(VecI2 pos, int code)
   {
      flt chr_u = flt(code % xsize);
      flt chr_v = flt(code / xsize);

      image->drawPart(
         Rect(this.screen_x + ((pos.x            ) * this.u * this.scale), this.screen_y - ((pos.y           ) * this.v * this.scale), 
              this.screen_x + ((pos.x + 1.0f  * 1) * this.u * this.scale), this.screen_y - ((pos.y - 1.0f * 1) * this.v * this.scale)),
         Rect(chr_u * this.u * this.scale, chr_v * this.v * this.scale, (chr_u + 1.0f) * this.u * this.scale, (chr_v + 1.0f) * v * this.scale)
      );
      
      #if 0
      flt xx = flt(pos.x);
      flt yy = flt(pos.y);
      D.text(0, -0.1, TextInt(pos.x) + "/"+TextInt(pos.y));
      D.text(0, -0.2, TextFlt(this.screen_x + xx * this.u * this.scale)+", "+ TextFlt(this.screen_y - yy * this.v * this.scale));
      D.text(0, -0.4, TextFlt(chr_u * this.u * this.scale)+", "+TextFlt(chr_v * this.v * this.scale));
      D.text(0, -0.3, TextFlt(this.screen_x + (xx + 1.0f) * this.u * this.scale) + ", " + TextFlt(this.screen_y - (yy + 1.0f) * v * this.scale));
      D.text(0, -0.5, TextFlt((chr_u + 1.0f) * this.u * this.scale) + ", " + TextFlt((chr_v + 1.0f) * v * this.scale));
      #endif
    }

private:
   ImagePtr image;
   flt u;
   flt v;
   flt screen_x;
   flt screen_y;
   int xsize;
   int ysize;
   flt scale;
}

