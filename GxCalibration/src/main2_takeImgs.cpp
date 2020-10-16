

#include "h2_takeImgs.hpp"

int main()
{
    TakeImg *tImg = new TakeImg();
    int status = TAKE_IMG_STATUS_TRUE_;

    status = tImg->TakeImgLoop();
    if(status != TAKE_IMG_STATUS_TRUE_)
    {
        return -1;
    }
    status = tImg->SaveXml();

    return 0;
}