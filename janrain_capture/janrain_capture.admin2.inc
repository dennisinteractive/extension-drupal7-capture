<?php

/**
 * @file
 * Admin settings menu for Capture 2.0
 */

/**
 * Sets up the admin settings form for this module.
 */
function janrain_capture_settings() {
  global $base_url;
  
  $janrain_capture_main = variable_get('janrain_capture_main2', array());
  $form['janrain_capture_main2'] = array(
    '#type' => 'fieldset',
    '#title' => t('Application Settings'),
    '#tree' => TRUE,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['janrain_capture_main2']['capture_app_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Application ID'),
    '#default_value' => !empty($janrain_capture_main['capture_app_id']) ? $janrain_capture_main['capture_app_id'] : '',
  );
  $form['janrain_capture_main2']['capture_client_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Client ID'),
    '#default_value' => !empty($janrain_capture_main['capture_client_id']) ? $janrain_capture_main['capture_client_id'] : '',
  );
  $form['janrain_capture_main2']['capture_client_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Client Secret'),
    '#default_value' => !empty($janrain_capture_main['capture_client_secret']) ? $janrain_capture_main['capture_client_secret'] : '',
  );
  $form['janrain_capture_main2']['capture_address'] = array(
    '#type' => 'textfield',
    '#title' => t('Capture URL'),
    '#default_value' => !empty($janrain_capture_main['capture_address']) ? $janrain_capture_main['capture_address'] : '',
    '#description' => t('For example, https://myapp.janraincapture.com.'),
  );
  $form['janrain_capture_main2']['engage_address'] = array(
    '#type' => 'textfield',
    '#title' => t('Engage URL'),
    '#default_value' => !empty($janrain_capture_main['engage_address']) ? $janrain_capture_main['engage_address'] : '',
    '#description' => t('For example, https://myapp.rpxnow.com.'),
  );
  
  $janrain_capture_ui = variable_get('janrain_capture_ui2', array());
  $form['janrain_capture_ui2'] = array(
    '#type' => 'fieldset',
    '#title' => t('UI Settings'),
    '#tree' => TRUE,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['janrain_capture_ui2']['profile_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Capture Profiles'),
    '#default_value' => isset($janrain_capture_ui['profile_enabled']) ? $janrain_capture_ui['profile_enabled'] : 1,
    '#description' => t('Enable/Disable overriding the standard Drupal Profiles'),
  );
  $form['janrain_capture_ui2']['registration_flow'] = array(
    '#type' => 'textfield',
    '#title' => t('Registration Flow'),
    '#default_value' => !empty($janrain_capture_ui['registration_flow']) ? $janrain_capture_ui['registration_flow'] : 'socialRegistration',
    '#description' => t('Change this only when instructed to do so<br/>(default: socialRegistration)'),
  );
  $form['janrain_capture_ui2']['recaptcha_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Recaptcha Public Key'),
    '#default_value' => !empty($janrain_capture_ui['recaptcha_key']) ? $janrain_capture_ui['recaptcha_key'] : '6LeVKb4SAAAAAGv-hg5i6gtiOV4XrLuCDsJOnYoP',
    '#description' => t('Your Recaptcha Public Key'),
  );
    
  $janrain_capture_federate = variable_get('janrain_capture_federate2', array());
  $form['janrain_capture_federate2'] = array(
    '#type' => 'fieldset',
    '#title' => t('Federate Settings (optional)'),
    '#tree' => TRUE,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['janrain_capture_federate2']['capture_sso_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable SSO'),
    '#default_value' => isset($janrain_capture_federate['capture_sso_enabled']) ? $janrain_capture_federate['capture_sso_enabled'] : 0,
    '#description' => t('Enable/Disable SSO for Capture 2.0'),
  );
  $form['janrain_capture_federate2']['capture_sso_address'] = array(
    '#type' => 'textfield',
    '#title' => t('Single sign on domain'),
    '#default_value' => !empty($janrain_capture_federate['capture_sso_address']) ? $janrain_capture_federate['capture_sso_address'] : '',
    '#description' => t('For example, myapp.janrainsso.com.'),
  );
  
  $janrain_capture_backplane = variable_get('janrain_capture_backplane2', array());
  $form['janrain_capture_backplane2'] = array(
    '#type' => 'fieldset',
    '#title' => t('Backplane Settings (optional)'),
    '#tree' => TRUE,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['janrain_capture_backplane2']['backplane_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Backplane'),
    '#default_value' => isset($janrain_capture_backplane['backplane_enabled']) ? $janrain_capture_backplane['backplane_enabled'] : 0,
    '#description' => t('Enable/Disable Backplane for Capture 2.0'),
  );

  $options = array(
    '1.2' => t('1.2'),
    '2' => t('2.0'),
  );

  $form['janrain_capture_backplane2']['backplane_version'] = array(
    '#type' => 'radios',
    '#title' => t('Backplane Version'),
    '#options' => $options,
    '#default_value' => $options['2'],
  );

  $form['janrain_capture_backplane2']['backplane_bus_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Backplane bus name'),
    '#default_value' => !empty($janrain_capture_backplane['backplane_bus_name']) ? $janrain_capture_backplane['backplane_bus_name'] : '',
    '#description' => t('For example, '.$_SERVER['SERVER_NAME']),
  );
  
  $janrain_capture_fields = variable_get('janrain_capture_fields2', array());
  $form['janrain_capture_fields2'] = array(
    '#type' => 'fieldset',
    '#title' => t('Field Settings'),
    '#tree' => TRUE,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['janrain_capture_fields2']['capture_no_email'] = array(
    '#type' => 'checkbox',
    '#title' => t('Don\'t store user email addresses in the Drupal database'),
    '#default_value' => isset($janrain_capture_fields['capture_no_email']) ? $janrain_capture_fields['capture_no_email'] : 0,
    '#description' => t('No real email addresses will be stored in the Drupal database; a placeholder value (UUID@localhost) will be stored instead. Note: you can also avoid storing email addresses as user names by enabling the Janrain Capture Mapping module and mapping a field (e.g. UUID) to Drupal user name'),
  );
  $form['janrain_capture_fields2']['capture_enforce_verification'] = array(
    '#type' => 'checkbox',
    '#title' => t('Require email verification'),
    '#default_value' => isset($janrain_capture_fields['capture_enforce_verification']) ? $janrain_capture_fields['capture_enforce_verification'] : 0,
    '#description' => t('Prompt users who have not verified their email address to do so before completing authentication'),
  );
  $form['janrain_capture_fields2']['capture_match_email'] = array(
    '#type' => 'checkbox',
    '#title' => t('Match users by email address'),
    '#default_value' => isset($janrain_capture_fields['capture_match_email']) ? $janrain_capture_fields['capture_match_email'] : 0,
    '#description' => t('Associate user and Capture accounts if both share the same email address.'),
    '#states' => array(
      'enabled' => array(
        ':input[name="janrain_capture_fields2[capture_enforce_verification]"]' => array('checked' => TRUE),
        ':input[name="janrain_capture_fields2[capture_no_email]"]' => array('checked' => FALSE),
      )
    ),
  );
  $form['janrain_capture_fields2']['capture_map_profile_pic'] = array(
    '#type' => 'checkbox',
    '#title' => t('Map profile pic'),
    '#default_value' => isset($janrain_capture_fields['capture_map_profile_pic']) ? $janrain_capture_fields['capture_map_profile_pic'] : 1,
    '#description' => t('Automatically map the Capture profile photo to the Drupal user profile picture.'),
  );
  $form['janrain_capture_fields2']['capture_preferred_photo_variant'] = array(
    '#type' => 'select',
    '#title' => t('Preferred photo variant'),
    '#options' => array(
      'small' => t('Small'),
      'normal' => t('Normal'),
      'large' => t('Large'),
      'square_thumbnail' => t('Square Thumbnail'),
      'original' => t('Original')
    ),
    '#default_value' => isset($janrain_capture_fields['capture_preferred_photo_variant']) ? $janrain_capture_fields['capture_preferred_photo_variant'] : 'small',
    '#description' => t('Select the preferred photo variant to use from the Capture profile. When it\'s not available, the "other" variant will be used as fallback.'),
  );

  $group = 'janrain_capture_share';
  $conf = variable_get($group, array());
  $form[$group] = array(
    '#type' => 'fieldset',
    '#title' => t('Social Share Settings (optional)'),
    '#group' => 'settings',
    '#tree' => TRUE,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => t('To configure social sharing providers visit <a href="@social_link" target="_blank">Janrain\'s rpxnow site</a>.', array('@social_link' => 'https://rpxnow.com')),
  );
  $form[$group]['enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable social share.'),
    '#default_value' => isset($conf['enabled']) ? $conf['enabled'] : 0,
    '#description' => t('Enable social sharing for the site. Don\'t forget to edit the social sharing settings for individual <a href="!content_types_link" target="_blank">content types</a>.', array('!content_types_link' => url('admin/structure/types/'))),
  );
  $sgroup = 'nodes';
  $sconf = isset($conf[$sgroup]) ? $conf[$sgroup] : array();
  $form[$group][$sgroup] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#title' => t('Social sharing settings for content'),
  );
  $form[$group][$sgroup]['default_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Default message for shared content'),
    '#default_value' => isset($sconf['default_message']) ? $sconf['default_message'] : JANRAIN_CAPTURE_SHARE_MESSAGE_NODES,
    '#description' => t('Specify the default message text (including tokens) to be used when sharing content. This setting can be overridden on the content type edit page.')
  );
  $form[$group][$sgroup]['default_linktext'] = array(
    '#type' => 'textfield',
    '#title' => t('Default link text for shared content'),
    '#default_value' => isset($sconf['default_linktext']) ? $sconf['default_linktext'] : JANRAIN_CAPTURE_SHARE_LINKTEXT_NODES,
    '#description' => t('Specify the default action description (including tokens) to be used when sharing content.  This setting can be overridden on the content type edit page.')
  );
  $form[$group][$sgroup]['default_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Default title for shared content'),
    '#default_value' => isset($sconf['default_title']) ? $sconf['default_title'] : JANRAIN_CAPTURE_SHARE_TITLE_NODES,
    '#description' => t('Specify the default title (including tokens) to be used when sharing content. This setting can be overridden on the content type edit page.')
  );
  $form[$group][$sgroup]['default_summary'] = array(
    '#type' => 'textfield',
    '#title' => t('Default description for shared content'),
    '#default_value' => isset($sconf['default_summary']) ? $sconf['default_summary'] : JANRAIN_CAPTURE_SHARE_SUMMARY_NODES,
    '#description' => t('Specify the default description (including tokens) to be used when sharing content. This setting can be overridden on the content type edit page.')
  );
  $form[$group][$sgroup]['providers'] = array(
    '#type' => 'textfield',
    '#title' => t('Comma-separated list of providers'),
    '#default_value' => isset($sconf['providers']) ? implode(', ', $sconf['providers']) : '',
    '#description' => t('Specify a comma-separated list of providers whose icons should be displayed on the share button. For example: facebook, twitter, yahoo, linkedin.')
  );
  $sgroup = 'comments';
  $sconf = isset($conf[$sgroup]) ? $conf[$sgroup] : array();
  $form[$group][$sgroup] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#title' => t('Social sharing settings for comments'),
  );
  $form[$group][$sgroup]['default_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Default message for shared comments'),
    '#default_value' => isset($sconf['default_message']) ? $sconf['default_message'] : JANRAIN_CAPTURE_SHARE_MESSAGE_COMMENTS,
    '#description' => t('Specify the default message text (including tokens) to be used when sharing comments. This setting can be overridden on the content type edit page.')
  );
  $form[$group][$sgroup]['default_linktext'] = array(
    '#type' => 'textfield',
    '#title' => t('Default link text for shared comments'),
    '#default_value' => isset($sconf['default_linktext']) ? $sconf['default_linktext'] : JANRAIN_CAPTURE_SHARE_LINKTEXT_COMMENTS,
    '#description' => t('Specify the default action description (including tokens) to be used when sharing comments.  This setting can be overridden on the content type edit page.')
  );
  $form[$group][$sgroup]['default_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Default title for shared comments'),
    '#default_value' => isset($sconf['default_title']) ? $sconf['default_title'] : JANRAIN_CAPTURE_SHARE_TITLE_COMMENTS,
    '#description' => t('Specify the default title (including tokens) to be used when sharing comments. This setting can be overridden on the content type edit page.')
  );
  $form[$group][$sgroup]['default_summary'] = array(
    '#type' => 'textfield',
    '#title' => t('Default description for shared comments'),
    '#default_value' => isset($sconf['default_summary']) ? $sconf['default_summary'] : JANRAIN_CAPTURE_SHARE_SUMMARY_COMMENTS,
    '#description' => t('Specify the default description (including tokens) to be used when sharing comments. This setting can be overridden on the content type edit page.')
  );

  // Add the token tree UI.
  if (module_exists('token')) {
    $form[$group]['token_help'] = array(
      '#theme' => 'token_tree',
      '#token_types' => array('user', 'node', 'comment', 'site'),
      '#global_types' => FALSE,
    );
  }
  else {
    $form[$group]['token_help'] = array(
      '#markup' => t('<a href="@token_module_link" target="_blank">Token</a> module is not enabled. Enable it if you want to use the token browser here.', array('@token_module_link' => 'http://drupal.org/project/token')),
    );
  }

  $form['janrain_capture_enforce'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enforce the use of Janrain Capture.'),
    '#default_value' => variable_get('janrain_capture_enforce', 0),
    '#description' => t('Make it impossible to login to this site outside of Janrain Capture. <br/>WARNING: DO NOT enable this setting until you have made at least one Capture user a Drupal Administrator and all of your user accounts have been migrated to Janrain Capture.'),
  );
  $form['#validate'] = array(
    'janrain_capture_settings_validate2',
  );
  $form['#submit'] = array(
    'janrain_capture_settings_submit2',
  );
  
  return system_settings_form($form);
}

/**
 * Validate callback for the settings form.
 */
function janrain_capture_settings_validate2($form, &$form_state) {
  if ($form_state['values']['janrain_capture_fields2']['capture_match_email'] && !$form_state['values']['janrain_capture_fields2']['capture_enforce_verification']) {
    form_set_error('janrain_capture_fields2][capture_match_email', t('You must enable the Enforce Email Verification setting in order to enable the Match Users on Email setting.'));
  }

  // Do not allow to enable social share if no engage URL is provided.
  if ($form_state['values']['janrain_capture_share']['enabled'] && empty($form_state['values']['janrain_capture_main2']['engage_address'])) {
    form_set_error('janrain_capture_main2][engage_address', t('You must provide an Engage URL in order to enable social share.'));
  }
}

/**
 * Submit callback for the settings form.
 */
function janrain_capture_settings_submit2($form, &$form_state) {
  //Parse engage app name to load.js path. If engage address is given engage app name will be parsed else default will be parsed.
  $engageAppUrl = $form_state['values']['janrain_capture_main2']['engage_address'];
  if($engageAppUrl!=''){
      $engageAppName  = strstr( parse_url( $engageAppUrl, PHP_URL_HOST ), '.', true);   
  } else {
      $engageAppName  = 'default';
  }
  $form_state['values']['janrain_capture_ui2']['load_js'] = 'd16s8pqtk4uodx.cloudfront.net/'.$engageAppName.'/load.js';
  // Store the comma-separated list of share providers as an array.
  if(!empty($form_state['values']['janrain_capture_share']['nodes']['providers'])) {
    $providers = $form_state['values']['janrain_capture_share']['nodes']['providers'];
    $providers = str_replace(' ', '', $providers);
    $providers = explode(',', $providers);
  } else {
    $providers = array();
  }
  $form_state['values']['janrain_capture_share']['nodes']['providers'] = $providers;

  // Rebuild the menu in case the "enforce" setting changed.
  variable_set('menu_rebuild_needed', TRUE);
}
