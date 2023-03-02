#include "helpers.h"
#include <math.h>
// Convert image to grayscale
int avgr(RGBTRIPLE x);
int avgg(RGBTRIPLE y);
int avgb(RGBTRIPLE z);
int MG(RGBTRIPLE arr1[], RGBTRIPLE arr2[], char p);
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = round((image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.0);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int ared = round(0.189 * image[i][j].rgbtBlue + 0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen);
            int agreen = round(0.168 * image[i][j].rgbtBlue + 0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen);
            int ablue = round(0.131 * image[i][j].rgbtBlue + 0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen);
            if (ared > 255)
            {
                ared = 255;
            }
            if (ablue > 255)
            {
                ablue = 255;
            }
            if (agreen > 255)
            {
                agreen = 255;
            }
            image[i][j].rgbtBlue = ablue;
            image[i][j].rgbtGreen = agreen;
            image[i][j].rgbtRed = ared;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    int halfw = (width - 1) / 2;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < halfw; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][(width - 1) - j];
            image[i][(width - 1) - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE a = copy[i + 1][j - 1], b = copy[i + 1][j], c = copy[i + 1][j + 1], d = copy[i][j - 1], e = copy[i][j], f = copy[i][j + 1], g = copy[i - 1][j - 1], h = copy[i - 1][j], k = copy[i - 1][j + 1];
            int avg = 9, flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, pxr, pxg, pxb;
            if (i == 0)
            {
                flag1 = 1;
                avg -= 3;
            }
            else if (i == height - 1)
            {
                avg -= 3;
                flag3 = 1;
            }
            if (j == width - 1)
            {
                avg -= 3;
                flag4 = 1;
            }
            else if (j == 0)
            {
                avg -= 3;
                flag2 = 1;
            }
            if (flag1 == 1 && flag2 == 1)
            {
                pxr = (avgr(e) + avgr(f) + avgr(h) + avgr(k)) / 4;
                pxb = (avgb(e) + avgb(f) + avgb(h) + avgb(k)) / 4;
                pxg = (avgg(e) + avgg(f) + avgg(h) + avgg(k)) / 4;
            }
            else if (flag1 == 1 && flag4 == 1)
            {
                pxr = (avgr(g) + avgr(h) + avgr(e) + avgr(d)) / 4;
                pxb = (avgb(g) + avgb(h) + avgb(e) + avgb(d)) / 4;
                pxg = (avgg(g) + avgg(h) + avgg(e) + avgg(d)) / 4;
            }
            else if (flag2 == 1 && flag3 == 1)
            {
                pxr = (avgr(b) + avgr(c) + avgr(e) + avgr(f)) / 4;
                pxb = (avgb(b) + avgb(c) + avgb(e) + avgb(f)) / 4;
                pxg = (avgg(b) + avgg(c) + avgg(e) + avgg(f)) / 4;
            }
            else if (flag3 == 1 && flag4 == 1)
            {
                pxr = (avgr(a) + avgr(b) + avgr(d) + avgr(e)) / 4;
                pxb = (avgb(a) + avgb(b) + avgb(d) + avgb(e)) / 4;
                pxg = (avgg(a) + avgg(b) + avgg(d) + avgg(e)) / 4;
            }
            else if (flag1 == 1)
            {
                pxr = (avgr(d) + avgr(e) + avgr(f) + avgr(g) + avgr(h) + avgr(k)) / 6;
                pxb = (avgb(d) + avgb(e) + avgb(f) + avgb(g) + avgb(h) + avgb(k)) / 6;
                pxg = (avgg(d) + avgg(e) + avgg(f) + avgg(g) + avgg(h) + avgg(k)) / 6;
            }
            else if (flag2 == 1)
            {
                pxr = (avgr(b) + avgr(c) + avgr(e) + avgr(f) + avgr(h) + avgr(k)) / 6;
                pxb = (avgb(b) + avgb(c) + avgb(e) + avgb(f) + avgb(h) + avgb(k)) / 6;
                pxg = (avgg(b) + avgg(c) + avgg(e) + avgg(f) + avgg(h) + avgg(k)) / 6;
            }
            else if (flag3 == 1)
            {
                pxr = (avgr(a) + avgr(b) + avgr(c) + avgr(d) + avgr(e) + avgr(f)) / 6;
                pxb = (avgb(a) + avgb(b) + avgb(c) + avgb(d) + avgb(e) + avgb(f)) / 6;
                pxg = (avgg(a) + avgg(b) + avgg(c) + avgg(d) + avgg(e) + avgg(f)) / 6;
            }
            else if (flag4 == 1)
            {
                pxr = (avgr(a) + avgr(b) + avgr(d) + avgr(e) + avgr(g) + avgr(h)) / 6;
                pxb = (avgb(a) + avgb(b) + avgb(d) + avgb(e) + avgb(g) + avgb(h)) / 6;
                pxg = (avgg(a) + avgg(b) + avgg(d) + avgg(e) + avgg(g) + avgg(h)) / 6;
            }
            else
            {
                pxr = (avgr(a) + avgr(b) + avgr(c) + avgr(d) + avgr(e) + avgr(f) + avgr(g) + avgr(h) + avgr(k)) / 9;
                pxb = (avgb(a) + avgb(b) + avgb(c) + avgb(d) + avgb(e) + avgb(f) + avgb(g) + avgb(h) + avgb(k)) / 9;
                pxg = (avgg(a) + avgg(b) + avgg(c) + avgg(d) + avgg(e) + avgg(f) + avgg(g) + avgg(h) + avgg(k)) / 9;
            }
            image[i][j].rgbtBlue = pxb;
            image[i][j].rgbtGreen = pxg;
            image[i][j].rgbtRed = pxr;
        }
    }
    return;
}
int avgr(RGBTRIPLE x)
{
    return x.rgbtRed;
}
int avgg(RGBTRIPLE y)
{
    return y.rgbtGreen;
}
int avgb(RGBTRIPLE z)
{
    return z.rgbtBlue;
}
void edges(int height, int width, RGBTRIPLE imag[height][width])
{
    RGBTRIPLE image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = imag[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE a = image[i + 1][j - 1], b = image[i + 1][j], c = image[i + 1][j + 1], d = image[i][j - 1], e = image[i][j], f = image[i][j + 1], g = image[i - 1][j - 1], h = image[i - 1][j], k = image[i - 1][j + 1];
            RGBTRIPLE s;
            s.rgbtBlue = 0;
            s.rgbtGreen = 0;
            s.rgbtRed = 0;
            if (i == 0)
            {
                if (j == 0)
                {
                    d = s;
                    g = s;
                }
                else if (j == width - 1)
                {
                    f = s;
                    g = s;
                }
                a = s;
                b = s;
                c = s;
            }
            else if (i == height - 1)
            {
                if (j == 0)
                {
                    a = s;
                    d = s;
                }
                else if (j == width - 1)
                {
                    c = s;
                    f = s;
                }
                g = s;
                h = s;
                k = s;
            }
            else if (j == width - 1)
            {
                c = s;
                f = s;
                k = s;
            }
            else if (j == 0)
            {
                a = s;
                d = s;
                g = s;
            }
            RGBTRIPLE gx[] = {a, c, d, f, g, k};
            RGBTRIPLE gy[] = {a, g, b, h, c, k};
            imag[i][j].rgbtBlue = MG(gx, gy, 'b');
            imag[i][j].rgbtGreen = MG(gx, gy, 'g');
            imag[i][j].rgbtRed = MG(gx, gy, 'r');
        }
    }
}
int MG(RGBTRIPLE arr1[], RGBTRIPLE arr2[], char p)
{
    int a[6];
    int b[6];
    if (p == 'b')
    {
        for (int i = 0; i < 6; i += 2)
        {
            a[i] = -arr1[i].rgbtBlue;
            a[i + 1] = arr1[i + 1].rgbtBlue;
            b[i] = -arr2[i].rgbtBlue;
            b[i + 1] = arr2[i + 1].rgbtBlue;
        }
    }
    else if (p == 'r')
    {
        for (int i = 0; i < 6; i += 2)
        {
            a[i] = -arr1[i].rgbtRed;
            a[i + 1] = arr1[i + 1].rgbtRed;
            b[i] = -arr2[i].rgbtRed;
            b[i + 1] = arr2[i + 1].rgbtRed;
        }
    }
    else if (p == 'g')
    {
        for (int i = 0; i < 6; i += 2)
        {
            a[i] = -arr1[i].rgbtGreen;
            a[i + 1] = arr1[i + 1].rgbtGreen;
            b[i] = -arr2[i].rgbtGreen;
            b[i + 1] = arr2[i + 1].rgbtGreen;
        }
    }
    int gx = 0, gy = 0;
    for (int i = 0; i < 6; i++)
    {
        gx += a[i];
        gy += b[i];
    }
    int n = round(sqrt(pow(gx, 2) + pow(gy, 2)));
    if (n > 255)
    {
        n = 255;
    }
    return n;
}