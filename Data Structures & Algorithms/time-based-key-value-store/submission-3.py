class TimeMap:

    def __init__(self):
        # Dictionary structure:
        # key -> list of (timestamp, value)
        #
        # Example:
        # {
        #     "foo": [(1, "bar"), (4, "bar2")]
        # }
        self.store = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        # If this key is being added for the first time,
        # create an empty list for its timeline.
        if key not in self.store:
            self.store[key] = []

        # Add the new timestamp and value to the key's timeline.
        #
        # Timestamps are given in increasing order,
        # so we can directly append.
        self.store[key].append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        # If the key was never stored, no value exists.
        if key not in self.store:
            return ""

        # Get the complete history for this key.
        #
        # Example:
        # values = [(1, "bar"), (4, "bar2")]
        values = self.store[key]

        # Binary search pointers
        left = 0
        right = len(values) - 1

        # Default answer if no timestamp is small enough
        answer = ""

        # We want the latest timestamp that is:
        #
        # saved_time <= requested timestamp
        while left <= right:
            # Find the middle index
            mid = (left + right) // 2

            # Get timestamp and value stored at mid
            saved_time, saved_value = values[mid]

            if saved_time <= timestamp:
                # This timestamp is valid because it is
                # not greater than the requested timestamp.
                answer = saved_value

                # There may be a newer valid timestamp
                # on the right side, so search right.
                left = mid + 1

            else:
                # This timestamp is too large.
                # Search on the left side.
                right = mid - 1

        # Return the latest valid value found
        return answer