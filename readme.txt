
1) It was a thought of whether the installation should naturally delete all files upon termination (calling of dtor)
However ultimately it made more sense that the API of the Installtion object leaves the files there if everything goes right.
Thus, the handle to 'graceful termination' is passed to the held files.