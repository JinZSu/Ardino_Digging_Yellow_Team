import sample_socket
import sample_parser
from Queue import Queue

def main() :
    gcs_to_robot = Queue(maxsize = -1)
    robot_to_gcs = Queue(maxsize = -1)
    commands = Queue(maxsize = -1)
    
    gcsSocket = sample_socket.SampleSocket("Socket_Thread",
                            gcs_to_robot,
                            robot_to_gcs,
                            remote_ip="192.168.1.105",
                            remote_socket=10010)
    gcsParser = sample_parser.SampleParser("Parser_Thread",
                                            robot_to_gcs,
                                            commands,
                                            gcs_to_robot)

    gcsSocket.init_socket()

    gcsSocket.start()
    gcsParser.start()


    command = ""

    print "CONNECTED."

    while command != "Exit" :
        if (len(command.strip()) > 0) :
            commands.put(command)

        command = raw_input()


    print "Exitting GCS"
    gcsSocket.stop()
    gcsParser.stop()

if __name__ == "__main__" :
    main(
