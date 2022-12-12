package application;

import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.Text;

public class HHGUI extends Application {

	private BorderPane borderpane;
	private static double HHDistance;
	private static boolean HareWin;

	public void initHareHoundGUI() {

		if (HareWin) {
			borderpane = new BorderPane();

			Text txtHareWin = new Text();
			txtHareWin.setX(200);
			txtHareWin.setY(300);
			txtHareWin.setFont(Font.font("Verdana", 20));
			txtHareWin.setFill(Color.BLACK);
			txtHareWin.setText("The Hare Wins!");
			borderpane.setCenter(txtHareWin);

			Text txtDistance = new Text();
			txtDistance.setX(150);
			txtDistance.setY(250);
			txtDistance.setFont(Font.font("Arial", 20));
			txtDistance.setFill(Color.BLACK);
			txtDistance.setText("The Distance between Hare and Hound is: " + HHDistance);
			borderpane.setBottom(txtDistance);

		} else {
			// HoundWins text
			borderpane = new BorderPane();
			Text txtHoundWin = new Text();
			txtHoundWin.setX(200);
			txtHoundWin.setY(300);
			txtHoundWin.setFont(Font.font("Times New Roman", 20));
			txtHoundWin.setFill(Color.BLUE);
			txtHoundWin.setText("The Hound Wins!");
			borderpane.setCenter(txtHoundWin);
			Text txtDistance = new Text();
			txtDistance.setX(150);
			txtDistance.setY(250);
			txtDistance.setFont(Font.font("Arial", 20));
			txtDistance.setFill(Color.BLACK);
			txtDistance.setText("The Distance between Hare and Hound is: " + HHDistance);
			borderpane.setBottom(txtDistance);

		}

	}

	public HHGUI() {
		initHareHoundGUI();
	}

	public static void main(String[] args) {
		HHGUI.launch(args);

	}

	@Override
	public void start(Stage primaryStage) {
		BorderPane borderPane = new BorderPane();
		// Put everything together:
		Scene scene = new Scene(borderPane, 600, 550);
		borderPane.setCenter(borderpane);
		primaryStage.setScene(scene);
		primaryStage.setTitle("Hare & Hound | Jeremiah Webb");
		primaryStage.setResizable(false);
		primaryStage.show();

	}

	public static void setDistance(double Distance) {

		HHDistance = Distance;
	}

	public double getDistance() {

		return (HHDistance);
	}

	public static void setHareWin(boolean HareWin1) {

		HareWin = HareWin1;
	}

	public boolean getHareWin() {

		return (HareWin);
	}

}
