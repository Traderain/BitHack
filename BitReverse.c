define ROR(data, ror) ( ((data)<<(32-(ror))) | ((data)>>(ror) )

void data_bit_rev(u32 *data, u32 size, u32 bpp)
{
    u32 i, tmp, mask;

    const volatile u32 masks[4]= 
    {   0xAAAAAAAA, 0x33333333, 0x0F0F0F0F, 0x00FF00FF  };

    for(i=0; i<size; i++)
    {
        tmp= data[i];

        // All fall throughs
        switch(bpp)
        {
        case 1:
            mask= masks[0];
            tmp= (mask & (tmp>>1)) | ((tmp&mask)<<1);
        case 2:
            mask= masks[1];
            tmp= (mask & (tmp>>2)) | ((tmp&mask)<<2);
        case 4:
            mask= masks[2];
            tmp= (mask & (tmp>>4)) | ((tmp&mask)<<4);
        case 8:
            mask= masks[3];
            tmp= (mask & (tmp>>8)) | ((tmp&mask)<<8);
        case 16:
            tmp= ROR(tmp, 16);          
        }
        data[i]= tmp;
    }
}
