import java.sql.*;
import java.util.Scanner;

public class JDBCExample {

    public static void main(String[] args) {

        // Database URL
        String url = "jdbc:oracle:thin:@localhost:1521:XE";

        // Oracle Username and Password
        String username = "system";
        String password = "root";

        // Scanner Object
        Scanner sc = new Scanner(System.in);

        try {

            // Load Oracle JDBC Driver
            Class.forName("oracle.jdbc.OracleDriver");

            // Create Connection
            Connection connection =
                    DriverManager.getConnection(
                            url,
                            username,
                            password);

            System.out.println("Connected to Oracle Database Successfully!");

            // Create Statement
            Statement stmt = connection.createStatement();

            int choice;

            // Menu Driven Program
            do {

                System.out.println("\n------ MENU ------");
                System.out.println("1. Insert");
                System.out.println("2. Update");
                System.out.println("3. Delete");
                System.out.println("4. Display");
                System.out.println("5. Exit");

                System.out.print("Enter Your Choice: ");
                choice = sc.nextInt();

                switch (choice) {

                    // INSERT
                    case 1:

                        System.out.print("Enter Employee ID: ");
                        int id = sc.nextInt();

                        sc.nextLine();

                        System.out.print("Enter First Name: ");
                        String fname = sc.nextLine();

                        System.out.print("Enter Last Name: ");
                        String lname = sc.nextLine();

                        System.out.print("Enter Email: ");
                        String email = sc.nextLine();

                        String insertQuery =
                                "INSERT INTO employees " +
                                "(employee_id, first_name, last_name, email, hire_date) " +
                                "VALUES (" +
                                id + ", '" +
                                fname + "', '" +
                                lname + "', '" +
                                email + "', SYSDATE)";

                        stmt.executeUpdate(insertQuery);

                        System.out.println("Record Inserted Successfully!");

                        break;

                    // UPDATE
                    case 2:

                        System.out.print("Enter Employee ID to Update: ");
                        int uid = sc.nextInt();

                        sc.nextLine();

                        System.out.print("Enter New Email: ");
                        String newEmail = sc.nextLine();

                        String updateQuery =
                                "UPDATE employees " +
                                "SET email = '" + newEmail +
                                "' WHERE employee_id = " + uid;

                        stmt.executeUpdate(updateQuery);

                        System.out.println("Record Updated Successfully!");

                        break;

                    // DELETE
                    case 3:

                        System.out.print("Enter Employee ID to Delete: ");
                        int did = sc.nextInt();

                        String deleteQuery =
                                "DELETE FROM employees " +
                                "WHERE employee_id = " + did;

                        stmt.executeUpdate(deleteQuery);

                        System.out.println("Record Deleted Successfully!");

                        break;

                    // DISPLAY
                    case 4:

                        String selectQuery =
                                "SELECT * FROM employees";

                        ResultSet rs =
                                stmt.executeQuery(selectQuery);

                        System.out.println("\nEmployee Records:");
                        System.out.println("-----------------------------------------------");

                        while (rs.next()) {

                            System.out.println(
                                    rs.getInt("employee_id") + "  "
                                            + rs.getString("first_name") + "  "
                                            + rs.getString("last_name") + "  "
                                            + rs.getString("email") + "  "
                                            + rs.getDate("hire_date"));
                        }

                        break;

                    // EXIT
                    case 5:

                        System.out.println("Exiting Program...");
                        break;

                    // INVALID CHOICE
                    default:

                        System.out.println("Invalid Choice!");
                }

            } while (choice != 5);

            // Close Connection
            connection.close();

            System.out.println("Database Connection Closed!");

        } catch (Exception e) {

            System.out.println(e);
        }
    }
}