# Goxq 
Open source, Lightweight Browser Engine written in C. This repository browser engine and render engine source code.

## About 
I don't want to create from this project a new Firefox or Chrome but just an little cool project on which i can have some fun. If
you like this idea and want tk contribute, the gate is open and you can do that in every moment! I will appreciate that.

First idea of creating an Browser Engine gone to my head about 3 year ago when i thought "How about creating an Browser?"
this idea beat me up because i was a new programmer and i didn't even know how does the browser work. After a year i've finally 
got something up and running it was [CoolCow](https://github.com/solindekdev/coolcow) this was supposed to be an super browser 
engine but after setting up UI the window was more laggy than fortnite on PC from '90. That wasn't good so i leaved that project
and gone on in this time I've created lot's of cool stuff, but the browser project was always my dream. That's how Goxq have been created.
## How does it work
But how does even Goxq work i will describe everything in steps what does the program do after launching it up:
1) Initialize Window and Renderer
2) Initialize and load fonts and images
3) Draw main browser UI
4) Wait for user inputs
5) Get into constant loop
6) Clean up fonts and unallocate all of the memory

The main entry point of this program is at [./main.c](./main.c) there's where all
of the magic is starting on
## FAQ
1) Why did i used C as programming language - Because of its simplicity i can create everything in C. I of course thought about other languages but no one of them got in to my heart like C, I was thinking about getting Rust up and running but I like that when I can do everything what I really can
2) Why SDL2 instead of GFLW or SFML - As well like the C i just like simplicity and this is what SDL gives me just a cool library in which i can do everything that I really want to! And also i was working in lot's of times so i know how to use it
3) Is creating a web engine in 2023 overkill? - Yes and No, Yes because web is now so overwhelmed there's is lots of technologies that you need to get up and running in your browser if you even would like to be used by others, but No because as I mentioned this wont be a big projects for millions of people but just a thing for me to learn how does browser work and kill my willingness to live lol
## Source code tree map
1) [js](./js/) - Folder that does Javascript stuff
2) [css](./css/) - Folder for CSS lexer and parser
3) [html](./html/) - Folder for HTML lexer and parser
4) [core](./core/) - Folder for some useful functions 
5) [render](./render/) - Folder for window management and render stuff also UI
   a) [components](./render/components/) - This folder holds UI Components
