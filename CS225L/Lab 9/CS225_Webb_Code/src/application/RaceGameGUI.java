package application;

import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import javafx.util.Duration;

public class RaceGameGUI extends Application {
	GridPane pane = new GridPane();
	String css = this.getClass().getResource("application.css").toExternalForm();

	private static double TurnCounter;

	public RaceGameGUI() {
		RaceGame rg = new RaceGame();

		pane.setAlignment(Pos.CENTER);
		pane.setPadding(new Insets(11, 12, 13, 14));
		pane.setHgap(5);
		pane.setVgap(5);

		Label label1 = new Label();
		label1.setId("Header");
		label1.setText("Racer 1 Distance:");
		Label label2 = new Label();
		label2.setId("Header");
		label2.setText("Racer 2 Distance:");
		Label label3 = new Label();
		label3.setId("Header");
		label3.setText("Racer 3 Distance:");
		Label label4 = new Label();
		label4.setId("Header");
		label4.setText("Racer 4 Distance:");

		Text RacerDistance1 = new Text();
		// RacerDistance1.setText("Test1 " + distances[0]);
		RacerDistance1.setId("Distance");
		Text RacerDistance2 = new Text();
		// RacerDistance2.setText("Test2 " + distances[1]);
		RacerDistance2.setId("Distance");
		Text RacerDistance3 = new Text();
		// RacerDistance3.setText("Test3 " + distances[2]);
		RacerDistance3.setId("Distance");
		Text RacerDistance4 = new Text();
		// RacerDistance4.setText("Test4 " + distances[3]);
		RacerDistance4.setId("Distance");

		// Create winner text
		Text winner = new Text();
		winner.setId("Winner");
		Text counter = new Text();

		counter.setId("Counter");

		/*
		 * // If Uzra wins if (WinnerName.equalsIgnoreCase(racer1)) {
		 * winner.setText("Uzra Wins!!!");
		 * 
		 * // If Fenix Wins } else if (WinnerName.equalsIgnoreCase(racer2)) {
		 * winner.setText("Fenix Wins!!!");
		 * 
		 * // If Drek wins } else if (WinnerName.equalsIgnoreCase(racer3)) {
		 * winner.setText("Drek Wins!!!");
		 * 
		 * // If Dijkstra wins } else { winner.setText("Dijkstra Wins!!!");
		 * 
		 * }
		 * 
		 */
		pane.add(label1, 0, 0);
		pane.add(label2, 0, 1);
		pane.add(label3, 0, 2);
		pane.add(label4, 0, 3);

		// Row 1

		pane.add(RacerDistance1, 1, 0);

		// Row 2

		pane.add(RacerDistance2, 1, 1);

		// Row 3

		pane.add(RacerDistance3, 1, 2);

		// Row 4

		pane.add(RacerDistance4, 1, 3);

		// Row 5

		pane.add(counter, 0, 4);

		// Row 6

		pane.add(winner, 0, 5);

		Timeline timeline = new Timeline();
		// make timeline repeat infinite number of times
		timeline.setCycleCount(Timeline.INDEFINITE);
		// timeline uses keyframes so make a keyframe
		// make a keyframe that runs every half second
		// keyframe can use a lambda expression for its action
		KeyFrame keyframe = new KeyFrame(Duration.millis(500), action -> {

			if (rg.gameOver() == true) {
				winner.setText("The winner is " + rg.getWinner());

				pane.add(winner, 0, 6);
				timeline.pause();
			}

			rg.moveRacers();
			double racer1Location = rg.getRacers()[0].getLocation();
			double racer2Location = rg.getRacers()[1].getLocation();
			double racer3Location = rg.getRacers()[2].getLocation();
			double racer4Location = rg.getRacers()[3].getLocation();
			TurnCounter = rg.setTurnCounter();

			RacerDistance1.setText(racer1Location + " meters");
			RacerDistance2.setText(racer2Location + " meters");
			RacerDistance3.setText(racer3Location + " meters");
			RacerDistance4.setText(racer4Location + " meters");
			counter.setText("Turn: " + TurnCounter);
		});

		// add keyframe to timeline
		timeline.getKeyFrames().add(keyframe);
		// start the timeline
		timeline.play();
	}

	@Override
	public void start(Stage stage) {
		Scene scene = new Scene(pane, 900, 500);
		scene.getStylesheets().add(css);

		stage.setScene(scene);

		stage.show();
	}

	public static void main(String[] args) {
		launch(args);
	}

	public static void setTurnCounter(int counter) {

		TurnCounter = counter;
	}

}
