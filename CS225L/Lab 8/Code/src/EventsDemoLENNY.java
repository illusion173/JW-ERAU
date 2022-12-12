import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.ButtonType;
import javafx.scene.control.CheckMenuItem;
import javafx.scene.control.Label;
import javafx.scene.control.Menu;
import javafx.scene.control.MenuBar;
import javafx.scene.control.MenuItem;
import javafx.scene.control.SeparatorMenuItem;
import javafx.scene.control.TextField;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Line;
import javafx.stage.Stage;
import javafx.application.Platform;

/**
 * Class for demonstrating JavaFX GUIs, shapes, and event handling.
 * 
 * @author Bobby Apelian (apelianr@my.erau.edu), October 2021 <br>
 * 				Based on original code by Sean Holden (holdens@my.erau.edu), October 2014 *         						
 */
public class EventsDemo extends Application {

	// Pane
	private BorderPane borderPane;

	// Menu stuff
	private MenuBar menuBar; // MenuBar
	private Menu menuFile, menuShapes, menuHelp; // Menus
	private MenuItem miClose; // Close MenuItem
	/** Menu item for showing/hiding a shape */
	private CheckMenuItem miCircle, miLine, miTriangle; // CheckMenuItems for each shape
	private MenuItem miShowAll, miClearAll; // Shows/clears all shapes
	private MenuItem miAbout; // Displays info about the program

	// Shapes
	/** Contains the shapes */
	private Pane shapePane;
	private Circle circle;
	/** The line that goes through the circle */
	private Line line;
	/** One of the lines that form the triangle in which the circle is inscribed */
	private Line triLineLeft, triLineRight, triLineBottom;
	/** Text Field for answering the question */
	private TextField textField;
	/** Labels for holding a question and answer */
	private Label questionLabel, answerLabel;
	/**Button for submitting answer */
	private Button submit;

	public void initEventsDemo() {
		// Create the BorderPane
		borderPane = new BorderPane();
		shapePane = new Pane();

		/* MENU CREATION */
		// Create MenuItems
		miClose = new MenuItem("Close");
		miCircle = new CheckMenuItem("Circle");
		miLine = new CheckMenuItem("Line");
		miTriangle = new CheckMenuItem("Triangle");
		miShowAll = new MenuItem("Show all");
		miClearAll = new MenuItem("Clear all");
		miAbout = new MenuItem("About...");
		// Create Menus
		menuFile = new Menu("File");
		menuShapes = new Menu("Shapes");
		menuHelp = new Menu("Help");
		// Create MenuBar
		menuBar = new MenuBar();
		// Add menu items to respective menus
		menuFile.getItems().add(miClose);
		menuShapes.getItems().addAll(miCircle, miLine, miTriangle, new SeparatorMenuItem(), miShowAll, miClearAll);
		menuHelp.getItems().add(miAbout);
		// Add menus to menuBar
		menuBar.getMenus().addAll(menuFile, menuShapes, menuHelp);

		/* SHAPE CREATION */
		// Circle
		circle = new Circle(100);
		circle.centerXProperty().bind(shapePane.widthProperty().divide(2));
		circle.centerYProperty().bind(shapePane.heightProperty().divide(1.5));
		circle.setFill(null);
		circle.setStroke(Color.BLACK);
		// Center line
		line = new Line();
		line.setStroke(Color.BLACK);
		line.startXProperty().bind(circle.centerXProperty());
		line.endXProperty().bind(circle.centerXProperty());
		line.startYProperty().bind(circle.centerYProperty().subtract(2 * circle.getRadius()));
		line.endYProperty().bind(circle.centerYProperty().add(circle.getRadius()));
		// Triangle
		triLineLeft = new Line();
		triLineRight = new Line();
		triLineBottom = new Line();
		triLineLeft.setStroke(Color.BLACK);
		triLineRight.setStroke(Color.BLACK);
		triLineBottom.setStroke(Color.BLACK);
		// Bindings - left line
		triLineLeft.startXProperty().bind(line.startXProperty());
		triLineLeft.startYProperty().bind(line.startYProperty());
		triLineLeft.endXProperty().bind(circle.centerXProperty().subtract(1.75 * circle.getRadius()));
		triLineLeft.endYProperty().bind(line.endYProperty());
		// Bindings - right line
		triLineRight.startXProperty().bind(line.startXProperty());
		triLineRight.startYProperty().bind(line.startYProperty());
		triLineRight.endXProperty().bind(circle.centerXProperty().add(1.75 * circle.getRadius()));
		triLineRight.endYProperty().bind(line.endYProperty());
		// Bindings - bottom line
		triLineBottom.startXProperty().bind(triLineLeft.endXProperty());
		triLineBottom.startYProperty().bind(triLineLeft.endYProperty());
		triLineBottom.endXProperty().bind(triLineRight.endXProperty());
		triLineBottom.endYProperty().bind(triLineRight.endYProperty());

		shapePane.getChildren().addAll(circle, line, triLineLeft, triLineRight, triLineBottom);
		shapePane.setStyle("-fx-background-color: beige;");

		circle.setVisible(false);
		line.setVisible(false);
		triLineBottom.setVisible(false);
		triLineLeft.setVisible(false);
		triLineRight.setVisible(false);
		
		// Text Field
		textField = new TextField();
		textField.setLayoutX(150);
		textField.setLayoutY(300);
		
		// Labels
		questionLabel = new Label("What series is the above shape from?");
		questionLabel.setLayoutX(135);
		questionLabel.setLayoutY(280);
		
		answerLabel = new Label("No answer yet.");
		answerLabel.setLayoutX(180);
		answerLabel.setLayoutY(330);
		
		//Button
		submit = new Button("Submit");
		submit.setLayoutX(300);
		submit.setLayoutY(300);
		
		shapePane.getChildren().addAll(textField, questionLabel, answerLabel, submit);

		miCircle.setOnAction(e-> {
			if(circle.isVisible() == true) {
				circle.setVisible(false);				
			} else {
				circle.setVisible(true);
			}});
		
		miLine.setOnAction(e-> {
			if(line.isVisible() == true) {
				line.setVisible(false);				
			} else {
				line.setVisible(true);
			}});
		
		miTriangle.setOnAction(e-> {
			if(triLineLeft.isVisible() && triLineRight.isVisible() && triLineBottom.isVisible()) {
				triLineLeft.setVisible(false);		
				triLineRight.setVisible(false);
				triLineBottom.setVisible(false);
			} else {
				triLineLeft.setVisible(true);		
				triLineRight.setVisible(true);
				triLineBottom.setVisible(true);
			}});
		
		miShowAll.setOnAction(e-> showAll(true));
		
		miClearAll.setOnAction(e-> showAll(false));
		
		submit.setOnAction(e-> checkAnswer(textField.getText()));
		
		miAbout.setOnAction(e-> showAbout());
		
		miClose.setOnAction(e-> Platform.exit());
	}
	
	

	/** Default constructor */
	public EventsDemo() {
		initEventsDemo();
	}

	@Override
	public void start(Stage primaryStage) throws Exception {

		/* TODO Add the event handlers here */

		// Put everything together:
		Scene scene = new Scene(borderPane, 450, 400);
		// Add the menubar and shapes to the borderpane
		borderPane.setTop(menuBar);
		borderPane.setCenter(shapePane);
		// Configure and display the stage
		primaryStage.setScene(scene);
		primaryStage.setTitle("JavaFX Fun Stuff");
		primaryStage.setResizable(false);
		primaryStage.show();
	}

	public static void main(String[] args) {
		EventsDemo.launch(args);
	}

	/** Shows information about the program in it's own window */
	private void showAbout() {

		final String aboutText = "This program was written by Bobby Apelian for use in the CS225 lab sections at Embry-Riddle Aeronautical University.  "
				+ "Modification and redistribution is highly encouraged.  No rights reserved.  Void where prohibited.  Batteries not included.";

		Alert popup = new Alert(Alert.AlertType.INFORMATION, aboutText, ButtonType.OK);

		popup.setHeaderText("About This Program");
		popup.setTitle("About");
		popup.showAndWait();

	}

	/** Checks all of the shape menu items to show all of the shapes */
	private void showAll(Boolean bool) {
		circle.setVisible(bool);
		line.setVisible(bool);
		triLineBottom.setVisible(bool);
		triLineLeft.setVisible(bool);
		triLineRight.setVisible(bool);
	}
	
	private void clearAll(Boolean bool) {
		circle.setVisible(bool);
		line.setVisible(bool);
		triLineBottom.setVisible(bool);
		triLineLeft.setVisible(bool);
		triLineRight.setVisible(bool);
	}
	
	public Boolean checkAnswer(String answer) {
		
		if(circle.isVisible() && line.isVisible() && triLineLeft.isVisible() && triLineRight.isVisible() && triLineBottom.isVisible()) {
			if(answer.equalsIgnoreCase("Harry Potter")) {
				answerLabel.setText("Yes its Harry Potter!!! :)");
				return true;
			}			
		}		
		if(circle.isVisible()) {
			if(answer.equalsIgnoreCase("circle")) {
				answerLabel.setText("Circle!");
				return true;
			}			
		}		
		if(line.isVisible()) {
			if(answer.equalsIgnoreCase("line")) {
				answerLabel.setText("Line!");
				return true;
			}			
		}		
		if(triLineLeft.isVisible() && triLineRight.isVisible() && triLineBottom.isVisible()) {
			if(answer.equalsIgnoreCase("triangle")) {
				answerLabel.setText("Triangle!");
				return true;
			}
			
		}
		answerLabel.setText("Nope that aint right!");
		return false;
	}
	
	

}
