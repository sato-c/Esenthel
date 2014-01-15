class Letter
{
public:
   enum
   {
      LETTER_W = 16,
      LETTER_H = LETTER_W,
      LETTER_X = 10,
      LETTER_Y = LETTER_X,    
   };
   
   static flt LETTER_SCALE = 1.0f;

   ~Letter();

   Letter(ImagePtr img = NULL, int width = LETTER_W, int height = LETTER_H, flt scale = LETTER_SCALE, int xcount = LETTER_X, int ycount = LETTER_Y)
   {
      this.image = img;
      this.scale = scale;

      if( img != NULL)
      {
         setSize(width, height, img);
      }
      
      this.xsize = xcount;
      this.ysize = ycount;
   }

   void set(ImagePtr img = NULL, int width = LETTER_W, int height = LETTER_H)
   {
      this.image = img;
      if( img != NULL)
      {
         setSize(width, height, img);
      }
   }

   void draw(VecI2 pos, int code)
   {
      flt chr_u = flt(code % xsize);
      flt chr_v = flt(code / xsize);
      
      
      image->drawPart(
         Rect(this.screenBase.x + ((pos.x            ) * this.displaySize.x * this.scale), this.screenBase.y - ((pos.y + 1.0f       ) * this.displaySize.y * this.scale), 
              this.screenBase.x + ((pos.x + 1.0f  * 1) * this.displaySize.x * this.scale), this.screenBase.y - ((pos.y ) * this.displaySize.y * this.scale)),
         Rect(chr_u * this.u * this.scale, chr_v * this.v * this.scale, (chr_u + 1.0f) * this.u * this.scale, (chr_v + 1.0f) * v * this.scale)
      );
      
      #if 0
      flt xx = flt(pos.x);
      flt yy = flt(pos.y);
      D.text(0, -0.1, TextInt(pos.x) + "/"+TextInt(pos.y));
      D.text(0, -0.2, TextFlt(this.screenBase.x + xx * this.u * this.scale)+", "+ TextFlt(this.screenBase.y - yy * this.v * this.scale));
      D.text(0, -0.4, TextFlt(chr_u * this.u * this.scale)+", "+TextFlt(chr_v * this.v * this.scale));
      D.text(0, -0.3, TextFlt(this.screenBase.x + (xx + 1.0f) * this.u * this.scale) + ", " + TextFlt(this.screenBase.y - (yy + 1.0f) * v * this.scale));
      D.text(0, -0.5, TextFlt((chr_u + 1.0f) * this.u * this.scale) + ", " + TextFlt((chr_v + 1.0f) * v * this.scale));

      VecI2 sc = D.screenToPixel(this.displaySize);
      D.text(0, -0.6, TextInt(sc.x) + "/" + TextInt(sc.y));
      #endif
    }

   Vec2 getDisplaySize()
   {
      return this.displaySize;
   }

private:
   ImagePtr image;

   flt scale;                 // display size
   flt u;                     // size of 1 letter
   flt v;

   Vec2 screenBase;           // screenSize
   Vec2 displaySize;
   VecI2 letterSize;

   int xsize;
   int ysize;

   void setSize( int width, int height, ImagePtr img )
   {
      this.u =  flt(width) / img->w();
      this.v = flt(height) / img->h();
      
      this.letterSize = VecI2(width, height);
      
      this.screenBase  = D.pixelToScreen(VecI2(0, 0));
      this.displaySize = D.pixelToScreenSize(VecI2(width, height));
   }
}
