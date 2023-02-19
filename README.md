# Goxq 
Open source, Lightweight Browser Engine written in C. This repository browser engine and render engine source code.

I don't want to create from this project a new Firefox or Chrome but just an little cool project on which i can have some fun. If
you like this idea and want tk contribute, the gate is open and you can do that in every moment! I will appreciate that.

First idea of creating an Browser Engine gone to my head about 3 year ago when i thought "How about creating an Browser?"
this idea beat me up because i was a new programmer and i didn't even know how does the browser work. After a year i've finally 
got something up and running it was [CoolCow](https://github.com/solindekdev/coolcow) this was supposed to be an super browser 
engine but after setting up UI the window was more laggy than fortnite on PC from '90. That wasn't good so i leaved that project
and gone on in this time I've created lot's of cool stuff, but the browser project was always my dream. That's how Goxq have been created.
# How does it work
But how does even Goxq work i will describe everything in steps what does the program do after launching it up:
1) Initialize Window and Renderer
2) Initialize and load fonts and images
3) Draw main browser UI
4) Wait for user inputs
5) Get into constant loop
6) Clean up fonts and unallocate all of the memory

The main entry point of this program is at [./main.c](./main.c) there's where all
of the magic is starting on
