//
//  vertext.glsl
//  TemplateProject
//
//  Created by Vidyadhar V. Thatte on 10/24/16.
//  Copyright © 2016 Ivan Safrin. All rights reserved.
//

attribute vec4 position;
uniform mat4 modelViewMatrix;
void main() {
    gl_Position = modelViewMatrix * position;
}
