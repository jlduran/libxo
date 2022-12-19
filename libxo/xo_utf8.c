/*
 * Copyright (c) 2022, Juniper Networks, Inc.
 * All rights reserved.
 * This SOFTWARE is licensed under the LICENSE provided in the
 * ../Copyright file. By downloading, installing, copying, or otherwise
 * using the SOFTWARE, you agree to be bound by the terms of that
 * LICENSE.
 * Phil Shafer, October 2022
 */

#include "xo.h"
#include "xo_utf8.h"

/**
 * Convert a codepoint to lower case.  This is amazingly complicated.
 * Annoyingly so.
 */
wchar_t
xo_utf8_wtolower (wchar_t wc)
{
    if ((0x0041 <= wc && 0x005a >= wc)
	|| (0x00c0 <= wc && 0x00d6 >= wc)
	|| (0x00d8 <= wc && 0x00de >= wc)
	|| (0x0391 <= wc && 0x03a1 >= wc)
	|| (0x03a3 <= wc && 0x03ab >= wc)
	|| (0x0410 <= wc && 0x042f >= wc)) {
	wc += 32;
  } else if (0x0400 <= wc && 0x040f >= wc) {
	wc += 80;
  } else if ((0x0100 <= wc && 0x012f >= wc)
	     || (0x0132 <= wc && 0x0137 >= wc)
	     || (0x014a <= wc && 0x0177 >= wc)
	     || (0x0182 <= wc && 0x0185 >= wc)
	     || (0x01a0 <= wc && 0x01a5 >= wc)
	     || (0x01de <= wc && 0x01ef >= wc)
	     || (0x01f8 <= wc && 0x021f >= wc)
	     || (0x0222 <= wc && 0x0233 >= wc)
	     || (0x0246 <= wc && 0x024f >= wc)
	     || (0x03d8 <= wc && 0x03ef >= wc)
	     || (0x0460 <= wc && 0x0481 >= wc)
	     || (0x048a <= wc && 0x04ff >= wc)) {
	wc |= 0x1;
  } else if ((0x0139 <= wc && 0x0148 >= wc)
	     || (0x0179 <= wc && 0x017e >= wc)
	     || (0x01af <= wc && 0x01b0 >= wc)
	     || (0x01b3 <= wc && 0x01b6 >= wc)
	     || (0x01cd <= wc && 0x01dc >= wc)) {
	wc += 1;
	wc &= ~0x1;
  } else {
	switch (wc) {
	case 0x0178: wc = 0x00ff; break;
	case 0x0243: wc = 0x0180; break;
	case 0x018e: wc = 0x01dd; break;
	case 0x023d: wc = 0x019a; break;
	case 0x0220: wc = 0x019e; break;
	case 0x01b7: wc = 0x0292; break;
	case 0x01c4: wc = 0x01c6; break;
	case 0x01c7: wc = 0x01c9; break;
	case 0x01ca: wc = 0x01cc; break;
	case 0x01f1: wc = 0x01f3; break;
	case 0x01f7: wc = 0x01bf; break;
	case 0x0187: wc = 0x0188; break;
	case 0x018b: wc = 0x018c; break;
	case 0x0191: wc = 0x0192; break;
	case 0x0198: wc = 0x0199; break;
	case 0x01a7: wc = 0x01a8; break;
	case 0x01ac: wc = 0x01ad; break;
	case 0x01af: wc = 0x01b0; break;
	case 0x01b8: wc = 0x01b9; break;
	case 0x01bc: wc = 0x01bd; break;
	case 0x01f4: wc = 0x01f5; break;
	case 0x023b: wc = 0x023c; break;
	case 0x0241: wc = 0x0242; break;
	case 0x03fd: wc = 0x037b; break;
	case 0x03fe: wc = 0x037c; break;
	case 0x03ff: wc = 0x037d; break;
	case 0x037f: wc = 0x03f3; break;
	case 0x0386: wc = 0x03ac; break;
	case 0x0388: wc = 0x03ad; break;
	case 0x0389: wc = 0x03ae; break;
	case 0x038a: wc = 0x03af; break;
	case 0x038c: wc = 0x03cc; break;
	case 0x038e: wc = 0x03cd; break;
	case 0x038f: wc = 0x03ce; break;
	case 0x0370: wc = 0x0371; break;
	case 0x0372: wc = 0x0373; break;
	case 0x0376: wc = 0x0377; break;
	case 0x03f4: wc = 0x03b8; break;
	case 0x03cf: wc = 0x03d7; break;
	case 0x03f9: wc = 0x03f2; break;
	case 0x03f7: wc = 0x03f8; break;
	case 0x03fa: wc = 0x03fb; break;

	default:
	    break;
	}
    }

    return wc;
}

/**
 * Convert a codepoint to upper case.  This is amazingly complicated.
 * Annoyingly so.
 */
wchar_t
xo_utf8_wtoupper (wchar_t wc)
{
    if ((0x0061 <= wc && 0x007a >= wc)
	|| (0x00e0 <= wc && 0x00f6 >= wc)
	|| (0x00f8 <= wc && 0x00fe >= wc)
	|| (0x03b1 <= wc && 0x03c1 >= wc)
	|| (0x03c3 <= wc && 0x03cb >= wc)
	|| (0x0430 <= wc && 0x044f >= wc)) {
	wc -= 32;
    } else if (0x0450 <= wc && 0x045f >= wc) {
	wc -= 80;
    } else if ((0x0100 <= wc && 0x012f >= wc)
	       || (0x0132 <= wc && 0x0137 >= wc)
	       || (0x014a <= wc && 0x0177 >= wc)
	       || (0x0182 <= wc && 0x0185 >= wc)
	       || (0x01a0 <= wc && 0x01a5 >= wc)
	       || (0x01de <= wc && 0x01ef >= wc)
	       || (0x01f8 <= wc && 0x021f >= wc)
	       || (0x0222 <= wc && 0x0233 >= wc)
	       || (0x0246 <= wc && 0x024f >= wc)
	       || (0x03d8 <= wc && 0x03ef >= wc)
	       || (0x0460 <= wc && 0x0481 >= wc)
	       || (0x048a <= wc && 0x04ff >= wc)) {
	wc &= ~0x1;
    } else if ((0x0139 <= wc && 0x0148 >= wc)
	       || (0x0179 <= wc && 0x017e >= wc)
	       || (0x01af <= wc && 0x01b0 >= wc)
	       || (0x01b3 <= wc && 0x01b6 >= wc)
	       || (0x01cd <= wc && 0x01dc >= wc)) {
	wc -= 1;
	wc |= 0x1;
    } else {
	switch (wc) {
	case 0x00ff: wc = 0x0178; break;
	case 0x0180: wc = 0x0243; break;
	case 0x01dd: wc = 0x018e; break;
	case 0x019a: wc = 0x023d; break;
	case 0x019e: wc = 0x0220; break;
	case 0x0292: wc = 0x01b7; break;
	case 0x01c6: wc = 0x01c4; break;
	case 0x01c9: wc = 0x01c7; break;
	case 0x01cc: wc = 0x01ca; break;
	case 0x01f3: wc = 0x01f1; break;
	case 0x01bf: wc = 0x01f7; break;
	case 0x0188: wc = 0x0187; break;
	case 0x018c: wc = 0x018b; break;
	case 0x0192: wc = 0x0191; break;
	case 0x0199: wc = 0x0198; break;
	case 0x01a8: wc = 0x01a7; break;
	case 0x01ad: wc = 0x01ac; break;
	case 0x01b0: wc = 0x01af; break;
	case 0x01b9: wc = 0x01b8; break;
	case 0x01bd: wc = 0x01bc; break;
	case 0x01f5: wc = 0x01f4; break;
	case 0x023c: wc = 0x023b; break;
	case 0x0242: wc = 0x0241; break;
	case 0x037b: wc = 0x03fd; break;
	case 0x037c: wc = 0x03fe; break;
	case 0x037d: wc = 0x03ff; break;
	case 0x03f3: wc = 0x037f; break;
	case 0x03ac: wc = 0x0386; break;
	case 0x03ad: wc = 0x0388; break;
	case 0x03ae: wc = 0x0389; break;
	case 0x03af: wc = 0x038a; break;
	case 0x03cc: wc = 0x038c; break;
	case 0x03cd: wc = 0x038e; break;
	case 0x03ce: wc = 0x038f; break;
	case 0x0371: wc = 0x0370; break;
	case 0x0373: wc = 0x0372; break;
	case 0x0377: wc = 0x0376; break;
	case 0x03d1: wc = 0x0398; break;
	case 0x03d7: wc = 0x03cf; break;
	case 0x03f2: wc = 0x03f9; break;
	case 0x03f8: wc = 0x03f7; break;
	case 0x03fb: wc = 0x03fa; break;

	default:
	    break;
	}
    }

    return wc;
}

/**
 * Return the codepoint to a UTF-8 character
 */
xo_utf8_wchar_t
xo_utf8_codepoint (const char *buf, size_t bufsiz, int len,
		   xo_utf8_wchar_t on_err)
{
    char b1 = *buf, b2, b3, b4;
    xo_utf8_wchar_t wc = 0;

    /*
     * The caller should really ensure this, but it seems odd to not
     * take a 'bufsiz' parameter, and if we take it, we should test it.
     */
    if (len <= 0 || (size_t) len > bufsiz)
	return on_err ?: XO_UTF8_ERR_TRUNCATED;

    /*
     * For determining the "shortest form", consider the following table::
     *
     *  Scalar Value               | Byte 1   | Byte 2   | Byte 3   | Byte 4
     *  00000000 00000000 0aaaaaaa | 0aaaaaaa |          |          |
     *  00000000 00000bbb baaaaaaa | 110bbbba | 10aaaaaa |          |
     *  00000000 ccccbbbb baaaaaaa | 1110cccc | 10cbbbba | 10aaaaaa |
     *  000ddddd dccccbbb baaaaaaa | 11110ddd | 10dddccc | 10cbbbba | 10aaaaaa
     *

     * For each length, 'zeroes' is set to the bits that should be zero.
     */

    /*
     * 'test' is the bits we extract
     * 'match' is the (const) value it must match
     * 'zeros' is the bits that must _not_ be zeros; if they are zero, then
     * the value is encoded in a "non-shortest form", which we reject as
     * directed by Unicode TR-36.
     */
    xo_utf8_wchar_t test, match, zeros;

    b1 &= xo_utf8_data_bits(len);
    if (len == 1) {
	wc = (unsigned char) b1; /* Make the simple case simple */

    } else {
	if (len == 2) {
	    b2 = buf[1];
	    test = b2 & 0xc0;
	    match = 0x80;
	    wc = (b1 << 6) | (b2 & 0x3f);
	    zeros = b1 & 0b00011110;

	} else if (len == 3) {
	    b2 = buf[1];
	    b3 = buf[2];
	    test = (b2 & 0xc0) << 8 | (b3 & 0xc0);
	    match = 0x8080;
	    wc = b1 << 12 | (b2 & 0x3f) << 6 | (b3 & 0x3f);
	    zeros = (b1 & 0b00001111) << 8 | (b2 & 0b00100000);

	} else if (len == 4) {
	    b2 = buf[1];
	    b3 = buf[2];
	    b4 = buf[3];
	    test = (b2 & 0xc0) << 16 | (b3 & 0xc0) << 8 | (b4 & 0xc0);
	    match = 0x808080;
	    wc = b1 << 18 | (b2 & 0x3f) << 12 | (b3 & 0x3f) << 6 | (b4 & 0x3f);
	    zeros = (b1 & 0b00000111) << 8 | (b2 & 0b00110000);

	} else return on_err ?: XO_UTF8_ERR_BAD_LEN;

	if (test != match)
	    return on_err ?: XO_UTF8_ERR_TRAILING;
	if (zeros == 0)
	    return on_err ?: XO_UTF8_ERR_NON_SHORT;
    }

    return wc;
}

/**
 * Inspect a string to see if it's valid UTF-8.  Returns either NULL
 * indicating success, or a pointer to the start of invalid character.
 */
char *
xo_utf8_nvalid (char *str, size_t len)
{
    char *cp;
    char *ep;
    xo_utf8_wchar_t wc;

    /*
     * Whiffle thru the string, looking for invalid characters.  We
     * don't need to look at 'len' since xo_utf8_codepoint will check
     * it.
     */
    for (cp = str, ep = str + len; cp < ep; cp += len) {
	len = xo_utf8_len(*cp);
	wc = xo_utf8_codepoint(cp, ep - cp, len, 0);
	if (wc < 0)
	    return cp;
    }

    return NULL;
}

/**
 * Ensure that a string is valid UTF-8 by replacing any invalid bytes
 * with the replacement byte.  If the replacement character is NUL (0),
 * then replacement will terminate with the first replacement.  Returns
 * the number of times a replacement is made.
 */
int
xo_utf8_nmakevalid (char *str, size_t len, char replacement)
{
    char *cp;
    char *ep;
    xo_utf8_wchar_t wc;
    int rc = 0;

    /*
     * Whiffle thru the string, looking for invalid characters.  We
     * don't need to look at 'len' since xo_utf8_codepoint will check
     * it.
     */
    for (cp = str, ep = cp + len; cp < ep; cp += len) {
	len = xo_utf8_len(*cp);
	wc = xo_utf8_codepoint(cp, ep - cp, len, 0);
	if (wc >= 0)
	    continue;

	rc += 1;
	len = 1;		/* We only consume one byte */
	*cp = replacement;

	if (replacement == 0)
	    break;
    }

    return rc;
}

/**
 * Convert a string to lower case.
 */
void
xo_utf8_nlower (char *str, size_t len)
{
    int ulen;

    char *cp = str, *ep = cp + len;
    for ( ; cp < ep; cp += ulen) {
	ulen = xo_utf8_len(*cp);
	wchar_t wc = xo_utf8_wcodepoint(str, len, ulen, ' ');
	wchar_t lc = xo_utf8_wtolower(wc);
	if (wc == lc)		/* Is it already lower? */
	    continue;

	if (ulen != xo_utf8_to_len(lc)) /* Sanity check that lengths match */
	    continue;

	xo_utf8_to_bytes(cp, len, lc);
    }
}

/**
 * Convert a string to upper case.
 */
void
xo_utf8_nupper (char *str, size_t len)
{
    int ulen;

    char *cp = str, *ep = cp + len;
    for ( ; cp < ep; cp += ulen) {
	ulen = xo_utf8_len(*cp);
	wchar_t wc = xo_utf8_wcodepoint(str, len, ulen, ' ');
	wchar_t uc = xo_utf8_wtoupper(wc);
	if (wc == uc)		/* Is it already upper? */
	    continue;

	if (ulen != xo_utf8_to_len(uc)) /* Sanity check that lengths match */
	    continue;


	xo_utf8_to_bytes(cp, len, uc);
    }
}

/**
 * UTF-8 version of strncasecmp(3), but with two lengths
 */
int
xo_ustrncasecmp (const char *s1, size_t s1_len, const char *s2, size_t s2_len)
{
    char s1c, s2c;
    wchar_t s1_wchar, s2_wchar;
    int s1_wlen, s2_wlen;

    while (s1_len > 0 && s2_len > 0) {
	s1c = *s1;
	s2c = *s2;

	if (!xo_is_utf8_byte(s1c)) {
	    if (xo_is_utf8_byte(s2c))
		/* s1 is ascii, s2 is utf8 */
		return -1;

	    /* Double ASCII */
	    if (s1c != s2c)
		return (s1c < s2c ? -1 : 1);

	    /* Move pointers and lengths */
	    s1 += 1;
	    s1_len -= 1;
	    s2 += 1;
	    s2_len -= 1;

	} else {
	    if (!xo_is_utf8_byte(s2c))
		/* s1 is utf8, s2 is ascii */
		return 1;

	    /* Double utf8 */
	    s1_wlen = xo_utf8_len(s1c);
	    s1_wchar = xo_utf8_wcodepoint(s1, s1_len, s1_wlen, ' ');

	    s2_wlen = xo_utf8_len(s2c);
	    s2_wchar = xo_utf8_wcodepoint(s2, s2_len, s2_wlen, ' ');

	    if (s1_wchar != s2_wchar)
		return (s1_wchar < s2_wchar ? -1 : 1);

	    /* Move pointers and lengths */
	    s1 += s1_wlen;
	    s1_len -= s1_wlen;
	    s2 += s2_wlen;
	    s2_len -= s2_wlen;
	}
    }

    return (s1_len > 0 ? -1 : s2_len > 0 ? -1 : 0);
}

/**
 * UTF-8 version of strncat(3) with strlcat safety, because why not be
 * safe?  We take care not to leave a half-made UTF-8 character at the
 * end, and turn invalid characters into spaces.
 */
size_t
xo_ustrlncat(char * restrict dst, const char * restrict append,
	     size_t dstsize, size_t count)
{
    size_t dstlen = strnlen(dst, dstsize);
    char *cp, *ep;
    int ulen;
    char first;
    wchar_t wc;

    if (dstsize == 0)
	return 0;

    for (cp = dst + dstlen, ep = dst + dstsize - 1; cp < ep && count > 0; ) {
	first = *append;
	if (xo_is_utf8_byte(first)) {
	    ulen = xo_utf8_len(first);
	    wc = xo_utf8_codepoint(append, count, ulen, ' ');
	    if (ulen < ep - cp)
		break;

	    xo_utf8_to_bytes(cp, ulen, wc);
	    cp += xo_utf8_to_len(wc);
	    append += ulen;
	    count -= ulen;

	} else {
	    /* ASCII */
	    *cp++ = first;
	    append += 1;
	    count -= 1;
	}
    }

    *cp = '\0';			/* Always NUL terminate */

    if (count == 0)
	return ep - cp;

    return ep - cp + count + 1;
}

/**
 * Truncate a UTF-8 string at the given length while keeping the
 * string UTF-8 valid.
 */
size_t
xo_utrunc (char *str, size_t len)
{
    char *ep = str + len;
    char ch = *ep;
    *ep = '\0';

    /*
     * Okay, we've done the minimal action: we've truncated the
     * string, but now we need to ensure that we didn't nibble off
     * half a multi-byte UTF-8 character.  Since we know the string
     * was valid to start with, we can look at the character we nuked
     * to know if we're in the middle.  First characters have both high
     * bits set, while 2nd, 3rd, and 4th characters have only the high
     * bit set.
     */
    while ((ch & 0xc0) == 0x80 && ep > str) {
	ep -= 1;
	ch = *ep;
	*ep = '\0';
    }

    return ep - str;
}


#if 0
    size_t s1_len = strlen(s1);
    size_t s2_len = strlen(s2);
    size_t clen = (len < s1_len) ? (len < s2_len ? len : s2_len)
	: (s1_len < s2_len ? s1_len : s2_len);

    char first_char = *s2;
    char first_lower;
    wchar_t first_wchar;
    wchar_t first_wlower;
    int first_wlen;

    /* Cache the first byte in upper or lower case */
    if (xo_is_utf8_byte(first_char)) {
	first_lower = 0;
	first_wlen = xo_utf8_len(first);
	first_wchar = xo_utf8_wcodepoint(s2, s2_len, first_wlen, ' ');
    } else {
	first_lower = tolower(first);
	first_ = 0;
    }

    for (;;) {
	char s1c = *s1;
	if (fl) {
	    if (xo_is_utf8_byte(s1c)) {
		/* s2 is ASCII, S2 */
		s1len = 
	    } else if (fl == s1c) {
	    } else {
	    }
	} else if (xo_is_utf8_byte(s1c)) {
	}
    }

}


#endif /* 0 */
