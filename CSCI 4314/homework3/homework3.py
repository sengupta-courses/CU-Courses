###########################################################################

# April 2019, Pourna Sengupta, pourna.sengupta@colorado.edu

# Code for HW3 CSCI 4314/5314 Dynamic Models in Biology

###########################################################################

import numpy as np

import math

import matplotlib.pyplot as plt


def flocking_python():
    # initializing plot
    plt.ion()
    fig = plt.figure()
    ax = fig.add_subplot(111)

    # initializing variables - constants

    # number of boids
    num = 400
    # number of frames
    frames = 100
    # axis limits
    limit = 100
    # doubled axis limits
    dlimit = limit * 2
    # initial position - gaussian spread
    startp = 10
    # initial velocity - gaussian spread
    startv = 10
    # time step
    delta = 1
    # max velocity
    vlimit = 1

    # initializing scaling factor variables - constants

    # attraction
    c1 = 0.00001
    # repulsion
    c2 = 0.00001
    # heading
    c3 = 1
    # randomness
    c4 = 0.001
    # static repulsion
    c5 = 0.001

    # initial position
    p = startp * np.random.randn(2, num)
    # initial velocity
    v = startv * np.random.randn(2, num)

    # initialize distance vector array
    d = np.zeros((2, num))

    # velocity calculations
    for i in range(0, frames):
        # initialize v1
        v1 = np.zeros((2, num))
        # initialize v2
        v2 = np.zeros((2, num))
        #initialize v5
        v5 = np.zeros((2, num))

        # compute v3
        # v3: average heading
        v3 = np.array([[np.mean(v[0, :]) * c3], [np.mean(v[1, :]) * c3]])

        # apply max velocity limit
        if np.linalg.norm(v3) > vlimit:
            v3 = v3 * vlimit / np.linalg.norm(v3)

        # distance calculations
        for n in range(0, num):
            for m in range(0, num):
                if m != n:
                    # calculate r
                    # r: vector from agent n to agent m
                    r = p[:, m] - p[:, n]

                    # check distance: x axis
                    if r[0] > dlimit / 2:
                        r[0] = r[0] - dlimit
                    elif r[0] < -dlimit / 2:
                        r[0] = r[0] + dlimit
                    # check distance: y axis
                    if r[1] > dlimit / 2:
                        r[1] = r[1] - dlimit
                    elif r[1] < -dlimit / 2:
                        r[1] = r[1] + dlimit

                    # calculate rmag
                    # rmag: distance between agent n and agent m
                    rmag = math.sqrt(math.pow(r[0], 2) + math.pow(r[1], 2))
                    np.append(d, rmag)

                    # compute  v5
                    # v5: obstacle/flock repulsion
                    v5[:, n] = v5[:, n] - (c5 * r)/(rmag ** 2)

                    # compute v1
                    # v1: flock attraction
                    v1[:, n] = v1[:, n] + c1 * r

                    # compute v2
                    # v2: flock repulsion
                    v2[:, n] = v2[:, n] - (c2 * r) / (math.pow(rmag, 2))

            # compute v4
            # v4: random movement generation
            v4 = c4 * np.random.randn(2, 1)

            # update flock velocity
            v[:, n] = v1[:, n] + v2[:, n] + v3[:, 0] + v4[:, 0]  # + v5[:, n]

            # update flock position
            p[:, n] = p[:, n] + v[:, n] * delta

            # set periodic boundary
            p[p > limit] -= limit * 2
            p[p < -limit] += limit * 2

            plt_num = 1
            j = i
            if j == 0 or j % 20 == 0 or j == 99:
                title = "Time: "
                if j != 100:
                    title = title + "{} of {}".format(j, frames)
                if j == 99:
                    title = title + "100 of {}".format(frames)

                ax.set(aspect='equal')

                plt.title(title, fontsize=12)
                plt.xticks(fontsize=8)
                plt.yticks(fontsize=8)

                # update plot
                line1, = ax.plot(p[0, 0], p[1, 0])
                ax.clear()

                # velocity arrows
                ax.quiver(p[0, :], p[1, :], v[0, :], v[1, :])

                # x and y limits
                plt.xlim(-limit, limit)
                plt.ylim(-limit, limit)

                line1.set_data(p[0, :], p[1, :])

                fig.canvas.draw()

                # print(plt_num)
                plt_num += 1

        # print("Length of Distances", len(d))
        plt.savefig("Test{}.png".format(c5), dpi=300)
        plt.show()


class Flock:
    def __init__(self):
        pass


flock_py = Flock()

flocking_python()
