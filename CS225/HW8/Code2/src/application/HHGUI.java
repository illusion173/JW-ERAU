package application;

import java.beans.EventHandler;

import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.stage.Stage;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.Text;

public class HHGUI extends Application {
	GridPane pane = new GridPane();
	String css = this.getClass().getResource("application.css").toExternalForm();
	private static double HHDistance;
	private static boolean HareWin;
	private Button Begin;
	Manager mgr = new Manager();

	public static void main(String[] args) {

		launch(args);
	}

	/*
	 * public void initHHGUI() {
	 * 
	 * pane.setAlignment(Pos.BASELINE_CENTER); pane.setPadding(new Insets(11, 12,
	 * 13, 14)); pane.setHgap(5); pane.setVgap(5); this.Begin = new Button();
	 * Begin.setText("Begin Game!"); Begin.setId("green");
	 * Begin.setAlignment(Pos.TOP_LEFT); pane.add(Begin, 0, 0);
	 * 
	 * Begin.setOnAction((event) -> { if (HareWin) { winnerHare(); } else {
	 * winnerHound(); } });
	 * 
	 * 
	 * }
	 */



	public void initHareHoundGUI() {
		if (HareWin) {
			winnerHare();
		} else {
			winnerHound();
		}
	}

	@Override
	public void start(Stage Stage) {

		pane.setAlignment(Pos.BASELINE_CENTER);
		pane.setPadding(new Insets(11, 12, 13, 14));
		pane.setHgap(5);
		pane.setVgap(5);
		this.Begin = new Button();
		Begin.setText("Begin Game!");
		Begin.setId("green");
		Begin.setAlignment(Pos.TOP_LEFT);
		pane.add(Begin, 0, 0);

		Begin.setOnAction((event) -> {
			initHareHoundGUI();
		});

		Stage.setTitle("Hare & Hound | Jeremiah Webb");
		Stage.setResizable(false);
		Scene scene = new Scene(pane, 900, 500);
		scene.getStylesheets().add(css);
		Stage.setScene(scene);
		Stage.show();
	}

	public void winnerHare() {
		// Hare Wins text
		HHDistance = mgr.getDistance();
		Text txtHareWin = new Text();
		txtHareWin.setFont(Font.font("Verdana", 20));
		txtHareWin.setFill(Color.BLACK);
		txtHareWin.setText("The Hare Wins!");
		pane.add(txtHareWin, 1, 0);
		Text txtDistance = new Text();
		txtDistance.setFont(Font.font("Arial", 20));
		txtDistance.setFill(Color.BLACK);
		txtDistance.setText("The Distance between Hare and Hound is: " + HHDistance);
		pane.add(txtDistance, 2, 0);

	}

	public void winnerHound() {
		// HoundWins text
		Text txtHoundWin = new Text();
		txtHoundWin.setFont(Font.font("Times New Roman", 20));
		txtHoundWin.setFill(Color.BLUE);
		txtHoundWin.setText("The Hound Wins!");
		pane.add(txtHoundWin, 1, 0);
		Text txtDistance = new Text();
		txtDistance.setFont(Font.font("Arial", 20));
		txtDistance.setFill(Color.BLACK);
		txtDistance.setText("The Distance between Hare and Hound is: " + HHDistance);
		pane.add(txtDistance, 2, 0);
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
