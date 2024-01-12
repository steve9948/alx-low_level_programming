#!/usr/bin/python3
"""states models for hbtn_0e_0_usa
"""
if __name__ == "__main__":
    import MySQLdb
    import sys

    db_host = "localhost"
    db_user = sys.argv[1]  # "username"
    db_password = sys.argv[2]  # "password"
    db_name = sys.argv[3]  # "database_name"
    port = 3306

    """Launch  Database connection"""
    db = MySQLdb.connect(
        host=db_host, user=db_user, passwd=db_password, db=db_name, port=port
    )
    """create a cursor to be used"""
    cursor = db.cursor()

    cursor.execute("SELECT * FROM states ORDER BY id ASC")
    rows = cursor.fetchall()

    """Print Rows"""
    for row in rows:
        print(row)

    '''close cursor'''
    cursor.close()

    """Close the connection to the DB"""
    db.close()

