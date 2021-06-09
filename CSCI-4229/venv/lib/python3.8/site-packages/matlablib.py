import matplotlib.pyplot as plt
import time
import IPython
from IPython import embed


# learn where site packages are stored! ref: https://stackoverflow.com/questions/122327/how-do-i-find-the-location-of-my-python-site-packages-directory
# python -c "import site; print(site.getsitepackages())"

# ref: https://stackoverflow.com/questions/5849800/what-is-the-python-equivalent-of-matlabs-tic-and-toc-functions
def TicTocGenerator():
    # Generator that returns time differences
    ti = 0           # initial time
    tf = time.time() # final time
    while True:
        ti = tf
        tf = time.time()
        yield tf-ti # returns the time difference

TicToc = TicTocGenerator() # create an instance of the TicTocGen generator

# This will be the main function through which we define both tic() and toc()

def toc(tempBool=True):
    # Prints the time difference yielded by generator instance TicToc
    tempTimeInterval = next(TicToc)
    if tempBool:
        print( "Elapsed time: %f seconds.\n" %tempTimeInterval )

def tic():
    # Records a time in TicToc, marks the beginning of a time interval
    toc(False)

def closefigures(plt):
    a=[plt.close(x) for x in range(1,100)] #bit dumb..how can i cound total # of figures?

def sayHey():
	print('hey')

def cc():
    import matplotlib.pyplot
    from IPython.testing.globalipapp import get_ipython  # https://pmbaumgartner.github.io/blog/testing-ipython-magics/
    ip = get_ipython()

    matplotlib.pyplot.close("all")

    #IPython.get_ipython().run_line_magic('reset', " -f in") # ref: https://ipython.readthedocs.io/en/stable/interactive/magics.html
    #ip.run_line_magic('reset', " -f in") # short form works
    ip.run_line_magic('reset', '-f ')  # short form works

def add3nums(a, b, c):
    return (a+b+c)

def keyboard():
    ## DROP TO KEYBOARD in the middle of a script. If you have iPYTHON SETUP can do this.
    # Ref: https://stackoverflow.com/questions/2158097/drop-into-python-interpreter-while-executing-function

    embed()
    #IPython.embed(header='WELCOME, keyboard() (exit to go back)',local_ns=locals(), global_ns=locals())
    #sys.tracebacklimit = 0




def quit_early():
    raise Exception('Halt', 'drop to keyboard')

def kill_background():
    # Kill python background tasks if gets hung up in pycharm
    import os
    os.system('tskill python')

def kill():
    kill_background()

class MyError(Exception):  # https://stackoverflow.com/questions/1319615/proper-way-to-declare-custom-exceptions-in-modern-python
    def __init__(self):
        # self.message = message
        # self.animal = animal
        pass

    def __str__(self):
        return self.message

    def _render_traceback_(self):
        print('ya got me')
    def __repr__(self):
        print('repr1')

# NO IDEA ABOUT THIS
# def showtraceback(self):
#     traceback_lines = traceback.format_exception(*sys.exc_info())
#     del traceback_lines[1]
#     message = ''.join(traceback_lines)
#     sys.stderr.write(message)
#
# import sys
# import traceback
# import IPython
# IPython.core.interactiveshell.InteractiveShell.showtraceback = showtraceback

def getPythonVariables():
    import os
    print(os.environ)  # Print a dict of env vars and their values
    # os.environ["PYTHONPATH"]  # Query a specific env var