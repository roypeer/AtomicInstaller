Later please change to markdown...

---- This is also to show some points during the development process, for the interviewer...
--- Have a section for actual readme (cli, testing etc) and a section for development process


1) It was a thought of whether the installation should naturally delete all files upon termination (calling of dtor)
However ultimately it made more sense that the API of the Installtion object leaves the files there if everything goes right.
Thus, the handle to 'graceful termination' is passed to the held files.

2) I am aware of some mixing between Wide-char versions of the API functions and the aliases versions. This was to tinker with it a bit.

3) 