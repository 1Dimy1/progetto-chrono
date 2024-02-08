//
// Created by dimy1 on 08/02/24.
//

#include "App.h"
#include "Frame.h"

bool App::OnInit(){
    //m_locale.Init();
    Frame *frame = new Frame();
    frame->Show(true);
    return true;
}