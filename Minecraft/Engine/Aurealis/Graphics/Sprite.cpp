#include <Aurealis/Graphics/Sprite.h>
#include <Aurealis/Graphics/TextureManager.h>

namespace Aurealis
{

	namespace Graphics
	{

		Sprite::Sprite()
		{
			imageNumber = 0;
			red = green = blue = alpha = 255;
		}

		TexturedVertex getVertex(float u,float v,float x, float y,float z)
		{
			TexturedVertex vert;
			vert.u = u;
			vert.v = v;
			vert.x = x;
			vert.y = y;
			vert.z = z;
			return vert;
		}

		Sprite::Sprite(const char* filename)
		{
			TextureManager::Instance()->LoadTexture(filename);

			imageNumber = TextureManager::Instance()->GetTextureNumber(filename);

			//generate wertices
			vertices = (TexturedVertex*)memalign(16, 4 * sizeof(TexturedVertex) );

			Image *img = TextureManager::Instance()->Images[imageNumber];

			width = img->Width;
			height = img->Height;

			float hPercent = (float)img->Height / (float)img->power2Height;
			float wPercent = (float)img->Width / (float)img->power2Width;

			if( vertices )
			{
				vertices[0] = getVertex(0.0f,0.0f,-img->Width/2,-img->Height/2,0.0f);
				vertices[1] = getVertex(0.0f,hPercent,-img->Width/2, img->Height/2,0.0f);
				vertices[2] = getVertex(wPercent,0.0f,img->Width/2,-img->Height/2,0.0f);
				vertices[3] = getVertex(wPercent,hPercent,img->Width/2, img->Height/2,0.0f);
			}

			sceKernelDcacheWritebackInvalidateRange(vertices, 4 * sizeof(TexturedVertex));
			red = green = blue = alpha = 255;
		}

		Sprite::Sprite(std::string filename, bool constOne)
		{
		    if(constOne)
            {
                TextureManager::Instance()->LoadConstTexture(filename);

                imageNumber = TextureManager::Instance()->GetConstTextureNumber(filename);

                //generate wertices
                vertices = (TexturedVertex*)memalign(16, 4 * sizeof(TexturedVertex) );

                Image *img = TextureManager::Instance()->ConstImages[imageNumber];

                width = img->Width;
                height = img->Height;

                float hPercent = (float)img->Height / (float)img->power2Height;
                float wPercent = (float)img->Width / (float)img->power2Width;

                if( vertices )
                {
                    vertices[0] = getVertex(0.0f,0.0f,-img->Width/2,-img->Height/2,0.0f);
                    vertices[1] = getVertex(0.0f,hPercent,-img->Width/2, img->Height/2,0.0f);
                    vertices[2] = getVertex(wPercent,0.0f,img->Width/2,-img->Height/2,0.0f);
                    vertices[3] = getVertex(wPercent,hPercent,img->Width/2, img->Height/2,0.0f);
                }

                sceKernelDcacheWritebackInvalidateRange(vertices, 4 * sizeof(TexturedVertex));
				red = green = blue = alpha = 255;
            }
		}

		Sprite::Sprite(int textureNumer)
		{
			imageNumber = textureNumer;

			//generate wertices
			vertices = (TexturedVertex*)memalign(16, 4 * sizeof(TexturedVertex) );

			Image *img = TextureManager::Instance()->Images[imageNumber];

			width = img->Width;
			height = img->Height;

			float hPercent = (float)img->Height / (float)img->power2Height;
			float wPercent = (float)img->Width / (float)img->power2Width;

			if( vertices )
			{
				vertices[0] = getVertex(0.0f,0.0f,-img->Width/2,-img->Height/2,0.0f);
				vertices[1] = getVertex(0.0f,hPercent,-img->Width/2, img->Height/2,0.0f);
				vertices[2] = getVertex(wPercent,0.0f,img->Width/2,-img->Height/2,0.0f);
				vertices[3] = getVertex(wPercent,hPercent,img->Width/2, img->Height/2,0.0f);
			}

			sceKernelDcacheWritebackInvalidateRange(vertices, 4 * sizeof(TexturedVertex));
				red = green = blue = alpha = 255;
		}

		Sprite::Sprite(int textureNumer, bool constOne)
		{
			imageNumber = textureNumer;

			//generate wertices
			vertices = (TexturedVertex*)memalign(16, 4 * sizeof(TexturedVertex));
            Image *img;
            if(constOne)
            {
                img = TextureManager::Instance()->ConstImages[imageNumber];
            }
			else
            {
                img = TextureManager::Instance()->Images[imageNumber];
            }

			width = img->Width;
			height = img->Height;

			float hPercent = (float)img->Height / (float)img->power2Height;
			float wPercent = (float)img->Width / (float)img->power2Width;

			if( vertices )
			{
				vertices[0] = getVertex(0.0f,0.0f,-img->Width/2,-img->Height/2,0.0f);
				vertices[1] = getVertex(0.0f,hPercent,-img->Width/2, img->Height/2,0.0f);
				vertices[2] = getVertex(wPercent,0.0f,img->Width/2,-img->Height/2,0.0f);
				vertices[3] = getVertex(wPercent,hPercent,img->Width/2, img->Height/2,0.0f);
			}

			sceKernelDcacheWritebackInvalidateRange(vertices, 4 * sizeof(TexturedVertex));
			red = green = blue = alpha = 255;
		}

		Sprite::Sprite(const char* filename,int startW,int startH,int endW,int endH)
		{
			TextureManager::Instance()->LoadTexture(filename);

			imageNumber = TextureManager::Instance()->GetTextureNumber(filename);

			//generate wertices
			vertices = (TexturedVertex*)memalign(16, 4 * sizeof(TexturedVertex) );

			Image *img = TextureManager::Instance()->Images[imageNumber];

			width = endW;
			height = endH;

			float hstart = (float)startH / (float)img->power2Height;
			float wstart = (float)startW / (float)img->power2Width;
			float hPercent = (float)(startH + endH) / (float)img->power2Height;
			float wPercent = (float)(startW + endW) / (float)img->power2Width;

			if( vertices )
			{
				vertices[0] = getVertex(wstart,hstart,-width/2,-height/2,0.0f);
				vertices[1] = getVertex(wstart,hPercent,-width/2, height/2,0.0f);
				vertices[2] = getVertex(wPercent,hstart,width/2,-height/2,0.0f);
				vertices[3] = getVertex(wPercent,hPercent,width/2, height/2,0.0f);
			}

			//sceKernelDcacheWritebackInvalidateAll();
			sceKernelDcacheWritebackInvalidateRange(vertices, 4 * sizeof(TexturedVertex));
			red = green = blue = alpha = 255;
		}

		Sprite::Sprite(int textureNumer,int startW,int startH,int endW,int endH)
		{
			imageNumber = textureNumer;

			//generate wertices
			vertices = (TexturedVertex*)memalign(16, 4 * sizeof(TexturedVertex) );

			Image *img = TextureManager::Instance()->Images[imageNumber];

			width = endW;
			height = endH;

			float hstart = (float)startH / (float)img->power2Height;
			float wstart = (float)startW / (float)img->power2Width;
			float hPercent = (float)(startH + endH) / (float)img->power2Height;
			float wPercent = (float)(startW + endW) / (float)img->power2Width;

			if( vertices )
			{
				vertices[0] = getVertex(wstart,hstart,-width/2,-height/2,0.0f);
				vertices[1] = getVertex(wstart,hPercent,-width/2, height/2,0.0f);
				vertices[2] = getVertex(wPercent,hstart,width/2,-height/2,0.0f);
				vertices[3] = getVertex(wPercent,hPercent,width/2, height/2,0.0f);
			}

			//sceKernelDcacheWritebackInvalidateAll();
			sceKernelDcacheWritebackInvalidateRange(vertices, 4 * sizeof(TexturedVertex));
			red = green = blue = alpha = 255;
		}

		Sprite::Sprite(Texture* texture, int startW, int startH, int endW, int endH)
		{
			//generate wertices
			vertices = (TexturedVertex*)memalign(16, 4 * sizeof(TexturedVertex));

			tex = texture;
			width = endW;
			height = endH;

			float hstart = (float)startH / (float)tex->pHeight;
			float wstart = (float)startW / (float)tex->pWidth;
			float hPercent = (float)(startH + endH) / (float)tex->pHeight;
			float wPercent = (float)(startW + endW) / (float)tex->pWidth;

			if (vertices)
			{
				vertices[0] = getVertex(wstart, hstart, -width / 2, -height / 2, 0.0f);
				vertices[1] = getVertex(wstart, hPercent, -width / 2, height / 2, 0.0f);
				vertices[2] = getVertex(wPercent, hstart, width / 2, -height / 2, 0.0f);
				vertices[3] = getVertex(wPercent, hPercent, width / 2, height / 2, 0.0f);
			}

			//sceKernelDcacheWritebackInvalidateAll();
			sceKernelDcacheWritebackInvalidateRange(vertices, 4 * sizeof(TexturedVertex));
			red = green = blue = alpha = 255;
		}

		Sprite::Sprite(int textureNumer,int startW,int startH,int endW,int endH, bool obr)
		{
			imageNumber = textureNumer;

			//generate wertices
			vertices = (TexturedVertex*)memalign(16, 4 * sizeof(TexturedVertex) );

			Image *img = TextureManager::Instance()->Images[imageNumber];

			width = endW;
			height = endH;

			float hstart = (float)startH / (float)img->power2Height;
			float wstart = (float)startW / (float)img->power2Width;
			float hPercent = (float)(startH + endH) / (float)img->power2Height;
			float wPercent = (float)(startW + endW) / (float)img->power2Width;

			if( vertices )
			{
				vertices[0] = getVertex(wstart,hstart,0,0,0.0f);
				vertices[1] = getVertex(wstart,hPercent,0,height,0.0f);
				vertices[2] = getVertex(wPercent,hstart,width,0,0.0f);
				vertices[3] = getVertex(wPercent,hPercent,width, height,0.0f);
			}

			//sceKernelDcacheWritebackInvalidateAll();
			sceKernelDcacheWritebackInvalidateRange(vertices, 4 * sizeof(TexturedVertex));
			red = green = blue = alpha = 255;
		}

        void Sprite::SetMapPos(int textureNumer,int startW,int startH,int endW,int endH)
		{
			imageNumber = textureNumer;
            free(vertices);
			//generate wertices
			vertices = (TexturedVertex*)memalign(16, 4 * sizeof(TexturedVertex) );

			Image *img = TextureManager::Instance()->Images[imageNumber];

			width = endW;
			height = endH;

			float hstart = (float)startH / (float)img->power2Height;
			float wstart = (float)startW / (float)img->power2Width;
			float hPercent = (float)(startH + endH) / (float)img->power2Height;
			float wPercent = (float)(startW + endW) / (float)img->power2Width;

			if( vertices )
			{
				vertices[0] = getVertex(wstart,hstart,0,0,0.0f);
				vertices[1] = getVertex(wstart,hPercent,0,height,0.0f);
				vertices[2] = getVertex(wPercent,hstart,width,0,0.0f);
				vertices[3] = getVertex(wPercent,hPercent,width, height,0.0f);
			}

			//sceKernelDcacheWritebackInvalidateAll();
			sceKernelDcacheWritebackInvalidateRange(vertices, 4 * sizeof(TexturedVertex));
		}

		Sprite::~Sprite()
		{
			free(vertices);
		}

		void Sprite::SetPosition(float x,float y)
		{
			posX = x;
			posY = y;
		}

        float Sprite::GetPositionX()
		{
			return posX;
		}

        float Sprite::GetPositionY()
		{
			return posY;
		}

		void Sprite::Scale(float x,float y)
		{
			scaleX = x;
			scaleY = y;

			for(int i=0; i<4; i++)
			{
				vertices[i].x = vertices[i].x * scaleX;
				vertices[i].y = vertices[i].y * scaleY;
			}

		}

		void Sprite::NewScale(float x)
		{
			for(int i=2; i<4; i++)
			{
				vertices[i].x = x;
			}
		}


		void Sprite::Alpha(float _alpha)
		{
			alpha = _alpha;
		}

		void Sprite::RGB(float _red, float _green, float _blue)
		{
			red = _red;
			green = _green;
			blue = _blue;
		}

		void Sprite::Draw()
		{
			sceGumPushMatrix();

			ScePspFVector3 loc = {posX,posY,0.0f};
			sceGumTranslate(&loc);

			sceGuEnable(GU_TEXTURE_2D);

			sceGuColor(GU_RGBA(red, green, blue, alpha));
			if (tex == NULL) {
				TextureManager::Instance()->SetTextureModeulate(imageNumber, GU_NEAREST, GU_NEAREST);
			}
			else {
				tex->bindTexture();
			}

			sceGumDrawArray(GU_TRIANGLE_STRIP,GU_TEXTURE_32BITF|GU_VERTEX_32BITF|GU_TRANSFORM_3D, 4, 0, vertices);

			sceGuDisable(GU_TEXTURE_2D);
			sceGumPopMatrix();
		}

        void Sprite::DrawLinear()
		{
			sceGumPushMatrix();

			ScePspFVector3 loc = {posX,posY,0.0f};
			sceGumTranslate(&loc);

			sceGuEnable(GU_TEXTURE_2D);

			sceGuColor(GU_RGBA(red, green, blue, alpha));
			TextureManager::Instance()->SetTextureModeulate(imageNumber, GU_LINEAR, GU_LINEAR);

			sceGumDrawArray(GU_TRIANGLE_STRIP,GU_TEXTURE_32BITF|GU_VERTEX_32BITF|GU_TRANSFORM_3D, 4, 0, vertices);

			sceGuDisable(GU_TEXTURE_2D);
			sceGumPopMatrix();
		}

        void Sprite::ConstDraw()
		{
			sceGumPushMatrix();

			ScePspFVector3 loc = {posX,posY,0.0f};
			sceGumTranslate(&loc);

			sceGuEnable(GU_TEXTURE_2D);
			TextureManager::Instance()->SetConstTexture(imageNumber,GU_NEAREST,GU_NEAREST);

			sceGumDrawArray(GU_TRIANGLE_STRIP,GU_TEXTURE_32BITF|GU_VERTEX_32BITF|GU_TRANSFORM_3D, 4, 0, vertices);

			sceGuDisable(GU_TEXTURE_2D);
			sceGumPopMatrix();
		}

		void Sprite::RemoveImage()
		{
			TextureManager::Instance()->RemoveTexture(imageNumber);
		}

	}

}

