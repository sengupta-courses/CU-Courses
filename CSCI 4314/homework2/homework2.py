import matplotlib.pyplot as plt
import math
import numpy as np
import random
import pylab

def navEff(): 
    print("PROBLEM 2 \n")
    w = np.arange(0.0, 1.0, 0.0001)
    totalDist = 0.0
    ne = list()
    for i in range(1000): 
        #x = v(w[i] * math.cos(thetai + thetaB) + (1.0 - w[i])* math.cos(thetai + thetaC))
        x = (w[i] * math.cos(math.pi/3) + (1.0 - w[i])* math.cos(math.pi/30))
        #y = v(w[i] * math.sin(thetai + thetaB) + (1.0 - w[i])* math.sin(thetai + thetaC))
        y = (w[i] * math.sin(math.pi/3) + (1.0 - w[i])* math.sin(math.pi/30))
        #Navigational Efficiency 
        #NE = Net distance in theta initial direction / total distance 
        d = math.sqrt(math.pow(x, 2) + math.pow(y, 2))
        totalDist = totalDist + d 
        ne.append(d / totalDist)

    #print(ne)
    ne.remove(1.0)
    maxN = max(ne)
    maxW = ne.index(maxN) 
    print("Maximum Navigational Efficiency (for theta(*CRW) = pi/30 and theta(*BRW) = pi/3): " , maxN, " when W = ", maxW + 1, "\n ")

class random_walks_python():
    print("PROBLEM 1 \n")
    def random_walks(self):
        N = 500  # no of steps per trajectory
        realizations = 50  # number of trajectories
        v = 1.0  # velocity (step size)
        theta_s_array = [round(math.pi / 24, 4), round(math.pi / 12, 4), round(math.pi / 3, 4)]  # the width of the random walk turning angle distribution (the lower it is, the more straight the trajectory will be)
        w_array = [0.0, 0.5,
                   1.0]  # w is the weighting given to the directional bias (and hence (1-w) is the weighting given to correlated motion)
        ratio_theta_s_brw_crw = 1
        plot_walks = 1
        count = 0

        efficiency_array = np.zeros([len(theta_s_array), len(w_array)])
        for w_i in range(len(w_array)):
            w = w_array[w_i]
            for theta_s_i in range(len(theta_s_array)):
                theta_s_crw = np.multiply(ratio_theta_s_brw_crw, theta_s_array[theta_s_i])
                theta_s_brw = theta_s_array[theta_s_i]
                x, y = self.BCRW(N, realizations, v, theta_s_crw, theta_s_brw, w)
                if plot_walks == 1:
                    count += 1
                    plt.figure(count)
                    plt.plot(x.T, y.T)
                    plt.axis('equal')
                efficiency_array[theta_s_i, w_i] = np.divide(np.mean(x[:, -1] - x[:, 0]), (v * N))
        b0, b05, b1 = efficiency_array[0]
        g0, g05, g1 = efficiency_array[1]
        r0, r05, r1 = efficiency_array[2]
        b = (b1 + g1 + r1) / 3
        c = (b0 + g0 + r0) / 3
        bc = (b05 + g05 + r05) / 3
        print("(a) Biased Random Walks (BRW): ", b, "\n")
        print("(b) Correlated Random Walks (CRW): ", c, "\n")
        print("(a) Equally Balanced Random Walks (BRW & CRW): ", bc, "\n")
        navEff()


            # plt.show()
        plt.figure()
        legend_array = []
        w_array_i = np.repeat(w_array, len(efficiency_array))
        for theta_s_i in range(0, len(theta_s_array)):
            legend_array.append(
                ["$\theta^{*CRW}=$", (ratio_theta_s_brw_crw * theta_s_array[theta_s_i]), "$\theta^{*BRW}=$",
                 (theta_s_array[theta_s_i])])

        plt.xlabel('w')
        plt.ylabel('navigational efficiency')
        wVals = list([0, 20, 30])
        plt.plot(wVals, efficiency_array[0], 'bo', label=legend_array[0])
        plt.plot(wVals, efficiency_array[1], 'go', label=legend_array[1])
        plt.plot(wVals, efficiency_array[2], 'ro', label=legend_array[2])
        plt.legend(loc='best', prop={'size': 5.2})
        plt.show()
    # The function generates 2D-biased correlated random walks
    def BCRW(self, N, realizations, v, theta_s_crw, theta_s_brw, w):
        X = np.zeros([realizations, N])
        Y = np.zeros([realizations, N])
        theta = np.zeros([realizations, N])
        X[:, 0] = 0
        Y[:, 0] = 0
        theta[:, 0] = 0

        for realization_i in range(realizations):
            for step_i in range(1, N):
                theta_crw = theta[realization_i][step_i - 1] + (theta_s_crw * 2.0 * (np.random.rand(1, 1) - 0.5))
                theta_brw = (theta_s_brw * 2.0 * (np.random.rand(1, 1) - 0.5))

                X[realization_i, step_i] = X[realization_i][step_i - 1] + (v * (w * math.cos(theta_brw))) + (
                            (1 - w) * math.cos(theta_crw))
                Y[realization_i, step_i] = Y[realization_i][step_i - 1] + (v * (w * math.sin(theta_brw))) + (
                            (1 - w) * math.sin(theta_crw))

                current_x_disp = X[realization_i][step_i] - X[realization_i][step_i - 1]
                current_y_disp = Y[realization_i][step_i] - Y[realization_i][step_i - 1]
                current_direction = math.atan2(current_y_disp, current_x_disp)

                theta[realization_i, step_i] = current_direction

        return X, Y

rdm_plt = random_walks_python()
rdm_plt.random_walks()




