# UE4PauseTest
 
Note: this assumes you have Visual Studio installed and set up for Unreal Engine. 

Here we'll go over how to add a subsystem that reports when the game has lost focus via a delegate call, so that we can bind to that delegate in blueprint.

Adding a class to the project: 
First we add a class to the project. In Unreal 5, select "Tools" in the top bar, and click on "New C++ Class"

Our class will be a game instance subsystem. This is easily accessed anywhere in the project, since the class is created after the game instance initializes.
So select "All Classes" at the top of the New Class window, search for "gameinstancesubsystem", select it, and click next.
![SelectGameInstanceSubsystem](https://user-images.githubusercontent.com/55777867/208835457-e432b776-2e00-4b36-8d60-ccb5a09c245a.png)

Make sure to select "Public" so the class is easily accessable, name it something sensible, and click Create. 
![CreateClass](https://user-images.githubusercontent.com/55777867/208835613-15d416ab-6050-4ce0-acb1-b3ee869da2a5.png)

If this is the first bit of C++ code you've added to your project, the system will go through the process of building visual studio project files, which may take some time. Eventually though Visual Studio will open and should auto-open your newly created .h and .cpp files.

First we'll make sure that the "Slate" system is added to the project's Build.cs file. Find a file named "[ProjectName]Build.cs" in the "Source/[ProjectName]" folder and add "Slate" in the space highlighted in this screenshot
![AddSlateToBuildCS](https://user-images.githubusercontent.com/55777867/208836151-b897d1ee-d8e4-40db-88ec-860d31139378.png)

Next, edit the new game instance subsystems's .h file. Here we override the "initialize" function, create a new event dispatcher in C++, and create a function in which to call this dispatcher.  For each function you can either right click -> "Create Definition", to add functions to the cpp file, or copy from the next image.
![PasteCopiedCodeIntoHFile](https://user-images.githubusercontent.com/55777867/208837809-69748dea-f157-41d1-948d-85b43128ef76.png)

in the CPP file, we'll make sure to include the needed SlateApplication.h file. Then we make sure to call the parent function in Initialize, and bind the slate delegate for window focus changing to our own function that will call our own dispatcher. This is to get around the fact that the SlateApplication delegates are not exposed to blueprint, and no thanks to editing engine code. Finally in our own function, we'll call our own dispatcher.
![PasteCopiedCodeIntoCPPFile](https://user-images.githubusercontent.com/55777867/208837759-c4d97046-14ed-4324-aed4-5124225da28c.png)

From here you should be able to click on "Build" in the top menu bar, and then "Build Solution". The project will compile and after some time you should se a "Completed" message in the Visual Studio output log. If there are errors, be sure that all code matches the code in the screenshots (don't forget the Build.cs file) and try again. Feel free to copy/paste from the relevant files in this repo.

With our code successfully compiled it's time to open the project and test this out.
Note: If you are using your own GameInstance BP class and using Event Initialize, be sure to "add call to parent function" on that event just in case. In theory you shouldn't need to but it doesn't hurt and I've been burned before.
In order to test, I've opened the level blueprint of whatever map works best, and added the BeginPlay function if it's not there already. Right-click and search for the subsystem you've just created, which is globally accessable since we created it as "game instance subsystem". From there bind to our dispatcher, and create a function to excecute whatever behavior we need when the game loses/gains focus. You probably want to pause the game if the "AppFocused" bool is false, but here we are just printing that bool to the screen in order to test. 
![BPTestBind](https://user-images.githubusercontent.com/55777867/208839247-609cdaf2-73a0-42cb-be8f-2e1bb6fc076f.png)

And that's it, bind to this dispatcher wherever you need it and good luck!
