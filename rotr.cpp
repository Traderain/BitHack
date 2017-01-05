inline unsigned CSaveRestoreSegment::_rotr ( unsigned val, int shift)
{
		register unsigned lobit;        /* non-zero means lo bit set */
		register unsigned num = val;    /* number to rotate */

		shift &= 0x1f;                  /* modulo 32 -- this will also make
										   negative shifts work */

		while (shift--) 
		{
				lobit = num & 1;        /* get high bit */
				num >>= 1;              /* shift right one bit */
				if (lobit)
						num |= 0x80000000;  /* set hi bit if lo bit was set */
		}

		return num;
}
