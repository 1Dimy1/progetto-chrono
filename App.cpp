//
// Created by dimy1 on 08/02/24.
//

#include "App.h"
#include "Frame.h"

bool App::OnInit(){
    Frame *frame = new Frame();
    frame->Show(true);
    return true;
}