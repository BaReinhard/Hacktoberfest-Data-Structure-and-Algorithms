# Data structure to store a Job
class Job:
    def __init__(self, start, finish, profit):

        self.start = start
        self.finish = finish
        self.profit = profit


# Function to find index of last job which doesn't conflict with the given job
# It performs a linear search on the given List of jobs
def findLastNonConflictingJob(jobs, n):

    # find index of the last job whose finish time is less than or equal to the
    # start time of the given job
    for i in reversed(range(n)):
        if jobs[i].finish <= jobs[n].start:
            return i

    # return negative index if no non-conflicting job is found
    return -1


# A recursive function to find maximum profit subset of non-overlapping
# jobs which are sorted according to finish time
def maxProfit(jobs, n):

    # base case
    if n < 0:
        return 0

    # sort jobs in increasing order of their finish times
    jobs.sort(key=lambda x: x.finish)

    # return if only one item is remaining
    if n == 0:
        return jobs[0].profit

    # find the index of last non-conflicting job with current job
    index = findLastNonConflictingJob(jobs, n)

    # include the current job and recur for non-conflicting jobs [0, index]
    incl = jobs[n].profit + maxProfit(jobs, index)

    # exclude the current job and recur for remaining items [0, n-1]
    excl = maxProfit(jobs, n - 1)

    # return the maximum profit by including or excluding current job
    return max(incl, excl)


if __name__ == '__main__':

    jobs = [
        Job(0, 6, 60), Job(1, 4, 30), Job(3, 5, 10),
        Job(5, 7, 30), Job(5, 9, 50), Job(7, 8, 10)
    ]

    print("The maximum profit is", maxProfit(jobs, len(jobs) - 1))
