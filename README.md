# 42_Cub3d

- [Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/raycasting.html)

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
