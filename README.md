# 42_Cub3d

- [Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/raycasting.html)
- [Ray Tracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html)
- [2D Vector Rotations](https://matthew-brett.github.io/teaching/rotation_2d.html)
- [Vector Rotations: Active & Passiva](https://phys.libretexts.org/Courses/University_of_California_Davis/UCD%3A_Physics_9HB__Special_Relativity_and_Thermal_Statistical_Physics/3%3A_Spacetime/3.1%3A_Vector_Rotations)
- [Scalar Product](https://www.mathcentre.ac.uk/resources/uploaded/mc-ty-scalarprod-2009-1.pdf)

## TODO:

- Map Validations:
    - [x] Check Map Boundaries;
- [ ] Open Images;
- [ ] WASD key hooks;
- [ ] FPS counter;

- [ ] Render
	- [ ] Double buffering

		Uses a different buffer to write the new frame
		instead of putting pixels directly in the screen.
		Prevents flickering from the delay putting the 1st to last pixel
	- [ ] Check if new frame is needed

		Only render new frame if there is moviment.
		Why render again, when nothing changed
	- [ ] Calculate items visible by the player
	- [ ] Draw items visible, in perspective
	- [ ] Draw ceiling and floor
